// buf, sizeof(buf) 很安全，不会溢出。
char buf[5];
fgets( buf, sizeof(buf), stdin );
