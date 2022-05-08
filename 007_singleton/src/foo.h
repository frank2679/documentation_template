#ifndef _FOO_H_
#define _FOO_H_

#include <iostream>
#include <map>
#include <string>

//==========================================================================
/**
 * @brief Make T as a singleton
 *
 * @tparam T
 */
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

//==========================================================================
/**
 * @brief SingletonV1 itself is a singleton
 *
 */
// template <typename T>
class SingletonV1 {
  public:
    static SingletonV1 &GetInstance() {
        static SingletonV1 instance;
        return instance;
    }
    // SingletonV1(SingletonV1 &&) = delete;
    // SingletonV1(const SingletonV1 &) = delete;
    void operator=(const SingletonV1 &) = delete;

    void Print() {
        std::cout << "\n===============\n";
        std::cout << &GetInstance() << ", size: " << database.size()
                  << std::endl;
        std::cout << "database: " << &database << std::endl;
    }

    std::map<std::string, int> database;

  public:
    SingletonV1() = default;
    virtual ~SingletonV1() = default;
};

//==========================================================================

class Foo : public SingletonV2<Foo> {
  public:
    Foo() = default;
    ~Foo() = default;
    void Print() {
        std::cout << "\n===============\n";
        std::cout << &GetInstance() << std::endl;
    }

    // int PrintFoo();
};

/**
 * @brief a singleton of a map
 *        use pointer return !!!
 *        return reference result to constructor
 *
 */
class SingletonV3 : public std::map<std::string, int> {
  public:
    static SingletonV3 *GetInstance() {
        static SingletonV3 database;
        return &database;
    }

    void Print() {
        std::cout << "\n===============\n";
        std::cout << GetInstance() << ", size: " << GetInstance()->size()
                  << std::endl;
    }

  protected:
    SingletonV3() = default;
    ~SingletonV3() = default;
};

//==========================================================================

/**
 * @brief singleton template, return pointer
 *
 * @tparam T
 */
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

  public:
    void Print() {
        std::cout << "\n===============\n";
        std::cout << "obj: " << this << std::endl;
        std::cout << SingletonV4<Foo4<T>>::GetInstance()
                  << ", size: " << SingletonV4<Foo4<T>>::GetInstance()->size()
                  << std::endl;
    }
};

#endif