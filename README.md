    Cross-platform snippets manager
    -------------------------------

    Dependencies:
        -   perl/bash/sed
        -   pt: https://github.com/monochromegane/the_platinum_searcher
        -   percol: https://github.com/mooz/percol

    Configuration:
        source ~/git/snippet-manager/sm.sh          # put it into your .zshrc/.bashrc

    Usages:
        sm keyword                                  # search and print
        csm keyword                                 # search and put into clipboard, uses pbcopy on macOS, xclip on Linux
        vism keyword                                # update snippet (I personally use vim)

    Advanced Usages:
        sm keyword -G java                          # search only java snippets, use `pt --help` to see more options

![](sm.gif)
