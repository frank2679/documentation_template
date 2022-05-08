这是一个基于 sphinx 和 reStructureText 的文档工程，可以部署在 github pages 上面。

## build and deploy the doc

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
