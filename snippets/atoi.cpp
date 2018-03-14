int atoi( const char *str )
{
    if ( !str ) { return 0; }

    int len = strlen( str );
    int sign = 1;

    const char *p = str;
    while ( *p == ' ' ) { ++p; }

    if ( *p == '+' ) { sign = +1; ++p; }
    if ( *p == '-' ) { sign = -1; ++p; }

    int i = 0;
    while( p && '0' <= *p && *p <= '9' ) {
        i = i * 10 + (*p - '0');
        ++p;
    }

    return i*sign;
}
