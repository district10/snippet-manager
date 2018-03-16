ptouch() {
    for p in "$@"; do
        _dir="$(dirname -- "$p")"
        [ -d "$_dir" ] || mkdir -p -- "$_dir"   // touch with ease
        touch -- "$p"                           // remove this line so not to touch the file
    done
}
