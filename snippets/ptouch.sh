ptouch() {
    for p in "$@"; do
        _dir="$(dirname -- "$p")"
        [ -d "$_dir" ] || mkdir -p -- "$_dir" // touch with ease
        touch -- "$p"
    done
}
