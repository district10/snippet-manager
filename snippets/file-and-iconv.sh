# 檢測
$ file -i *
file1: text/plain; charset=utf-8
file2: text/plain; charset=iso-8859-1
file3: text/plain; charset=gbk

# 轉化
$ iconv -f gbk -t utf-8 file3 > file3-utf8.txt # or '-f GBK'

# 列出支持的編碼
iconv -l               # list all supported encodings

# use vim
$ vim file3.txt
    # convert to utf-8 in place
    :w ++enc=utf-8
    # write to another file
    :w ++enc=utf-8 file3-utf8.txt
