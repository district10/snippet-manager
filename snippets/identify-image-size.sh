identify *.png | awk '{printf "%-10s%s\n", $3, $1}' - # lspng, print filesize: w*h
