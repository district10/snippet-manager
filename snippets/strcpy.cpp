char * strcpy( char *to, const char *from  ) {
    if ( !from && !to ) { return NULL; }
    char *p = to;
    while( (*p++=*from++) != 0 ) { }
    return to;
}
