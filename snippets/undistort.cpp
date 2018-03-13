// image undistort, given K, k1, k2, p1, p2
cv::Mat image = cv::imread(image_file, 0);
int rows = image.rows, cols = image.cols;
cv::Mat image_undistort = cv::Mat(rows, cols, CV_8UC1);
for (int v = 0; v < rows; v++) {
    for (int u = 0; u < cols; u++) {
        double x = (u-cx)/fx;
        double y = (v-cy)/fy;
        double r = sqrt(x*x+y*y);
        double u_distorted = (x*(1.0+k1*r*r+k2*r*r*r*r) + 2.0*p1*x*y + p2*(r*r+2.0*x*x)) * fx + cx;
        double v_distorted = (y*(1.0+k1*r*r+k2*r*r*r*r) + 2.0*p2*x*y + p1*(r*r+2.0*y*y)) * fy + cy;
        if (u_distorted >= 0 && v_distorted >= 0 && u_distorted < cols && v_distorted < rows) {
            image_undistort.at<uchar>(v, u) = image.at<uchar>((int) v_distorted, (int) u_distorted);
        } else {
            image_undistort.at<uchar>(v, u) = 0;
        }
    }
}
