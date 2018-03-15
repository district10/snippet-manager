// batch rename
for i in *.mp3; do mv "$i" "$(echo "$i" | tr ' ' '-')"; done
for i in *.pdf; do mv "$i" $(echo "$i" | tr ' [A-Z]' '-[a-z]'); done
find * -type f | sed -e "p;s/ /_/g;" | sed -e "s/^/\"/" -e "s/$/\"/" | xargs -n2 mv
