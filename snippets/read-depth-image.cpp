Mat d1 = imread ( argv[3], CV_LOAD_IMAGE_UNCHANGED ); // 16 bit unsigened
vector<Point3f> pts_3d;
vector<Point2f> pts_2d;
for ( DMatch m:matches ) {
    ushort d = d1.ptr<unsigned short> (int ( keypoints_1[m.queryIdx].pt.y )) [ int ( keypoints_1[m.queryIdx].pt.x ) ];
    if ( d == 0 ) continue;
    float dd = d/5000.0;
    Point2d p1 = pixel2cam ( keypoints_1[m.queryIdx].pt, K );
    pts_3d.push_back ( Point3f ( p1.x*dd, p1.y*dd, dd ) );
    pts_2d.push_back ( keypoints_2[m.trainIdx].pt );
}

Mat r, t;
// Input vector of distortion coefficients
// k_1, k_2, p_1, p_2[, k_3...
assumed.
solvePnP ( pts_3d, pts_2d, K, Mat(), r, t, false );
Mat R;
cv::Rodrigues ( r, R ); // r (rotation vector) -> R (rotation matrix)

bundleAdjustment ( pts_3d, pts_2d, K, R, t );
