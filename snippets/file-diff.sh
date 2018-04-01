cat <filename> | sort | uniq -d             # 只显示重复的行，每行只显示一次
cat <filename> | sort | uniq -D             # 只显示重复的行
cat <filename> | sort | uniq -i             # 忽略大小写
cat <filename> | sort | uniq -u             # 只显示只出现一次的行

sort <file1> <file2> | uniq -d              # 交集, intersection
sort <file1> <file2> | uniq                 # 并集, union
sort <file1> <file2> <file2> | uniq -u      # 差集, difference
sort <file1> <file2> | uniq -u              # 对称差集, symmetric difference
