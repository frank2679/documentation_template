# 目的
这个项目目的提升自己的软件设计及用C++编程的能力，包括**设计模式**，**C++编程**. 
关键结果
1. 完成常见的设计模式的代码

# 计划

主要参考资料为
1. 大话设计模式，程杰
2. 设计模式之美，王争
3. Effective C++，Mayler

7周，4月11号-5月底，读完并实现上述三个内容。


## build the doc

预准备 sphinx conda 环境
需要提前安装

```bash
pip install sphinx
pip install recommonmark
pip install sphinx-markdown-tables
pip install mkdocs
```

1. 切到 sphinx conda 环境下
2. 到 doc 路径下 make
3. 创建一个新的 worktree 及分支 gh-pages
4. 将 make 生成的网页内容拷贝到 gh-pages，提交上传到 github