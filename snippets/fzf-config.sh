# fzf config
export FZF_DEFAULT_COMMAND='
  (git ls-tree -r --name-only HEAD ||
         find . -path "*/\.*" -prune -o -type f -print -o -type l -print |
        sed s/^..//) 2> /dev/null'
