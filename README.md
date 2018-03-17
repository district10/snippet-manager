    Cross-platform snippets manager (a command-line tool)
    -----------------------------------------------------

    Dependencies:
        -   perl/bash/sed
        -   grepping tool: `pt` or `ag` (they have almost same usage)
                +   pt: https://github.com/monochromegane/the_platinum_searcher
                        go get a binary from github release page for your platform
                +   ag: https://github.com/ggreer/the_silver_searcher
                        apt-get install silversearcher-ag
        -   live filtering tool: `percol`
                +   percol: https://github.com/mooz/percol
                        pip install percol

    Configuration:
        source ~/git/snippet-manager/sm.sh          # put it into your .zshrc/.bashrc

    Usages:
        sm keyword                                  # search and print
        csm keyword                                 # search and put into
                                                      clipboard, uses pbcopy on macOS, xclip on Linux
        vism keyword                                # update snippet (I personally use vim)

    Advanced Usages:
        sm keyword -G java                          # search only java snippets, use
                                                      `pt --help` to see more options

    The above commands will search snippets in current directory,
    if you want to search in this repo, use `q`, `cq`, `viq`  respectively.

    We suppose code snippet is no more than 50 lines, if want something else, you can e.g.
    `export sm_n_line=100`.

    ---

    跨平台命令行代码片段管理工具
    -----------------------

    依赖项:
        -   perl/bash/sed (通常系统已自带)
        -   文件夹下文本搜索工具: pt 或 ag (用起来都一样, 装一个就行)
                +   pt: https://github.com/monochromegane/the_platinum_searcher
                        github 的 release 页面上可以下载二进制
                +   ag: https://github.com/ggreer/the_silver_searcher
                        Ubuntu 上安装: apt-get install silversearcher-ag
        -   文本动态过滤工具: percol
                +   percol: https://github.com/mooz/percol
                        pip install percol

    安装配置:
        source ~/git/snippet-manager/sm.sh          # 放到你的 .zshrc 或 .bashrc 里

    使用方法:
        sm keyword                                  # 搜索 keyword, 动态过滤, 并打印搜到的文件
        csm keyword                                 # 同上, 不打印而是放到剪切板
        vism keyword                                # 不打印也不放到剪切板, 而是编辑 snippet

    高级使用方法:
        sm keyword -G java                          # 只搜索 java 后缀的文本, 更多使用请参考 pt 的文档

    上面的代码会在当前文件夹下搜代码片段, 想要搜本仓库下的代码片段, 可以相应地用 `q`, `cq` 或是 `viq`.

    我们假定了代码文件长度不超过 50, 你可以通过 `export sm_n_line` 来覆盖这个设置.

![](sm.gif)
