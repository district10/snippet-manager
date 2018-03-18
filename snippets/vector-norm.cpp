// gradient
Eigen::Vector2d delta (
    gray.ptr<uchar>(y)[x+1] - gray.ptr<uchar>(y)[x-1],  // dx
    gray.ptr<uchar>(y+1)[x] - gray.ptr<uchar>(y-1)[x]   // dy
);
if ( delta.norm() < 50 ) {
}
