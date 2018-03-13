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
        smp keyword                                 # search and put into clipboard, you may need alias `xclip -selection primary` to `pbcopy` on Linux
        smvi keyword                                # update snippet (I personally use vim)

![](sm.gif)
