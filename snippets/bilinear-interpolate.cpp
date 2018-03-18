float getPixelValueByBilinearInterpolation ( float x, float y ) {
    uchar* data = & image_->data[ int ( y ) * image_->step + int ( x ) ];
    float xx = x - floor ( x );
    float yy = y - floor ( y );
    // A---------B  interpolated =
    // | (dx,dy) |      A * (1-dx)*(1-dy) +
    // |         |      B * (dx)*(1-dy) +
    // |         |      C * (1-dx)*(dy) +
    // C---------D      D * (dx)*(dy);
    return float (
            (1-xx)*(1-yy) * data[0] +
            xx *(1-yy) * data[1] +
            (1-xx)*   yy  * data[image_->step] +
            xx *   yy  * data[image_->step+1]
            );
}
