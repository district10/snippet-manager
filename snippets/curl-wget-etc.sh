## This function determines which http get tool the system has installed and returns an error if there isnt one
function getConfiguredClient() {
    if  command -v curl &>/dev/null; then
        configuredClient="curl"
    elif command -v wget &>/dev/null; then
        configuredClient="wget"
    elif command -v http &>/dev/null; then
        configuredClient="httpie"
    elif command -v fetch &>/dev/null; then
        configuredClient="fetch"
    else
        echo "Error: This tool reqires either curl, wget, httpie or fetch to be installed." >&2
        return 1
    fi
}

httpGet() {
  case "$configuredClient" in
    curl)  curl -A curl -s "$@" ;;
    wget)  wget -qO- "$@" ;;
    httpie) http -b GET "$@" ;;
    fetch) fetch -q "$@" ;;
  esac
}
