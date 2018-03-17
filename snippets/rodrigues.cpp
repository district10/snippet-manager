Mat r, t;
solvePnP ( pts_3d, pts_2d, K, Mat(), r, t, false ); // OpenCV PnP
Mat R;
cv::Rodrigues ( r, R ); // rotation vector to rotation matrix
