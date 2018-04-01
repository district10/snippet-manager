ls -l |awk '{print $5 " " $0;}'| sort -n | cut -d " " -f 2- # sort by filesize
