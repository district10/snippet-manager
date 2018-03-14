const char *str2int( char buf[], int value ) {
    if( value < 0 ) {
        buf = '-';
        return convert( buf+1, -value );
    }

    static char zero = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char *p = buf;
    do {
        *p++ = zero[value%10];
        value /= 10;
    } while (value != 0);
    *p = '\0';
    std::reverse(buf, p);
    return p;
}
