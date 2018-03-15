cat file.txt | iconv -f utf-8 -t gbk | iconv -f utf-8 -t latin1 | iconv -f gbk -t utf-8
