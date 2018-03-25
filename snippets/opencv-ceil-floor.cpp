// floor, ceil
CV_INLINE int cvFloor( float value ) {
    int i = (int)value;
    return i - (i > value);
}

CV_INLINE int cvCeil( float value ) {
    int i = (int)value;
    return i + (i < value);
}
