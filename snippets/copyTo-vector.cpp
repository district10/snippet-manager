cv::Mat pt = cv::Mat(pole->pt_).clone();
cv::Mat pt0 = R_enu_ecef * pt + t_enu_ecef;
vector<double> vec;
// copyTo vector
pt0.copyTo(vec);
