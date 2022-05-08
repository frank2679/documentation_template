1. 实现一个单例。
2. 在单例上加一个模板参数。
3. 实现用模板产生多个单例（database）。成功实现参考 V4

注意点
1. 单例类要用 pointer 返回，而不是 reference，后者会有 constructor 动作（原因 todo）
2. 继承单例类的时候注意要保证 class name 和单例模板参数一致，不然会生出一个怪胎。
3. singleton有两种写法，原因是既然自己要变成单例类，那需要是可以被构造/析构的，不然传给单例类模板后无法创建该单例类。
   1. 直接写，constructor/deconstructor 可以 protected
   2. 继承一个singleton，constructor/deconstructor 一定要是 public

正确实现如下：
```cpp
template <typename T> class SingletonV4 {
  public:
    static T *GetInstance() {
        static T instance;
        return &instance;
    }
    SingletonV4(T &&) = delete;
    SingletonV4(const T &) = delete;
    void operator=(const T &) = delete;

  protected:
    SingletonV4() = default;
    virtual ~SingletonV4() = default;
};

template <typename T>
class Foo4 : public SingletonV4<Foo4<T>>, public std::map<std::string, T> {
  public:
    Foo4() = default;
    ~Foo4() = default;
    void Print() {
        std::cout << "\n===============\n";
        std::cout << SingletonV4<Foo4<T>>::GetInstance()
                  << ", size: " << SingletonV4<Foo4<T>>::GetInstance()->size()
                  << std::endl;
    }
};
```

下面这种实现不行，每次 `auto database_str = Database<std::string>::GetInstance();` 都会获取到不同的database.

```cpp
template <typename T> class SingletonV2 {
  public:
    static T &GetInstance() {
        static T instance;
        return instance;
    }
    SingletonV2(T &&) = delete;
    SingletonV2(const T &) = delete;
    void operator=(const T &) = delete;

  protected:
    SingletonV2() = default;
    virtual ~SingletonV2() = default;
};

// make multiple singletons
template <typename T>
class Database : public std::map<std::string, T>,
                 public SingletonV2<Database<T>> {
  public:
    Database() = default;
    ~Database() = default;
};
```



# singleton with smart pointer
一个 database 单例是一个 map 类，创建的成员