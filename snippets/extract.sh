# extracted from oh-my-zsh plugin
(*.tar.gz|*.tgz) tar zxvf "$1"
(*.tar.bz2|*.tbz|*.tbz2) tar xvjf "$1"
(*.tar.xz|*.txz)
    tar --xz --help &> /dev/null \
    && tar --xz -xvf "$1" \
    || xzcat "$1" | tar xvf -
(*.tar.zma|*.tlz)
    tar --lzma --help &> /dev/null \
    && tar --lzma -xvf "$1" \
    || lzcat "$1" | tar xvf -
(*.tar) tar xvf "$1"
(*.gz) (( $+commands[pigz] )) && pigz -d "$1" || gunzip "$1"
(*.bz2) bunzip2 "$1"
(*.xz) unxz "$1"
(*.lzma) unlzma "$1"
(*.Z) uncompress "$1"
(*.zip|*.war|*.jar|*.sublime-package|*.ipsw|*.xpi|*.apk) unzip "$1" -d $extract_dir
(*.rar) unrar x -ad "$1"
(*.7z) 7za x "$1"
