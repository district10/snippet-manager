al(){
    if [ ! -z $1 ]; then
        if [ $1 = "ls" ]; then
            _list
        elif [ $1 = "add" ]; then
            _add $2 $3
        elif [ $1 = "rm" ]; then
            _remove $2
        elif [ $1 = "-h" ]; then
            echo "Usage:"
            echo "al add [name] [value]        # add alias with name and value"
            echo "al rm [name]                 # remove alias by name"
            echo "al ls                        # alias list"
            echo "al [name]                    # execute alias associate with [name]"
            echo "al -v                        # version information"
            echo "al -h                        # help"
        elif [ $1 = "-v" ]; then
            echo "aliasme 1.1.2"
            echo "visit https://github.com/Jintin/aliasme for more information"
        else
            _jump $1
        fi
    fi
}
