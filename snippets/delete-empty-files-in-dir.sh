rm `find . -iname "*.json" | xargs ls -lh {} 2>/dev/null | tr -s ' ' | cut -d ' ' -f 5,9 | grep ^0B | sed -e "s/^0B //" | tr '\n' ' '` # delete empty files in dir
