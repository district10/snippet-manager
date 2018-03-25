// OutputArray _descriptors)
if( nkeypoints == 0 ) {
    _descriptors.release();
} else {
    _descriptors.create(nkeypoints, 32, CV_8U);
    descriptors = _descriptors.getMat();
}
