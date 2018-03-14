size_t strlen( const char *str ) {
    const char *s = str;
    while( *s ) { ++s; }
    return s-str;
}
