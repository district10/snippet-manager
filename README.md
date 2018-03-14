    Cross-platform snippets manager (a command-line tool)
    -----------------------------------------------------

    Dependencies:
        -   perl/bash/sed
        -   grepping tool: pt (https://github.com/monochromegane/the_platinum_searcher)
        -   live filtering tool: percol (https://github.com/mooz/percol)

    Configuration:
        source ~/git/snippet-manager/sm.sh          # put it into your .zshrc/.bashrc

    Usages:
        sm keyword                                  # search and print
        csm keyword                                 # search and put into clipboard, uses pbcopy on macOS, xclip on Linux
        vism keyword                                # update snippet (I personally use vim)

    Advanced Usages:
        sm keyword -G java                          # search only java snippets, use `pt --help` to see more options

    (The above commands will search snippets in current directory, if you want to search in this repo, use `q`, `cq`, `viq`  respectively)

    ---

    跨平台命令行代码片段管理工具
    ----------------------------

    依赖项:
        -   perl/bash/sed (通常系统已自带)
        -   文件夹下文本搜索工具: pt (https://github.com/monochromegane/the_platinum_searcher)
        -   文本动态过滤工具: percol (https://github.com/mooz/percol)

    安装配置:
        source ~/git/snippet-manager/sm.sh          # 放到你的 .zshrc 或 .bashrc 里

    使用方法:
        sm keyword                                  # 搜索 keyword, 动态过滤, 并打印搜到的文件
        csm keyword                                 # 同上, 不打印而是放到剪切板
        vism keyword                                # 不打印也不放到剪切板, 而是编辑 snippet

    高级使用方法:
        sm keyword -G java                          # 只搜索 java 后缀的文本, 更多使用请参考 pt 的文档

    (上面的代码会在当前文件夹下搜代码片段, 想要搜本仓库下的代码片段, 可以相应地用 `q`, `cq` 或是 `viq`)

![](sm.gif)
