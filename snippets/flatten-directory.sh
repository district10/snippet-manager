find __DIR_NAME__ -type f | sed -e "p;s/\//____/g;" | sed -e "s/^/\"/" -e "s/$/\"/" | xargs -n2 cp // flatten directory
