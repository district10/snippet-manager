Mat pose_estimation_2d2d (  std::vector<KeyPoint> keypoints_1,
                            std::vector<KeyPoint> keypoints_2,
                            std::vector< DMatch > matches,
                            Mat& R, Mat& t )
{
    Mat K = ( Mat_<double> ( 3,3 ) << 520.9, 0, 325.1, 0, 521.0, 249.7, 0, 0, 1 );

    vector<Point2f> points1, points2;
    for ( int i = 0; i < ( int ) matches.size(); i++ ) {
        points1.push_back ( keypoints_1[matches[i].queryIdx].pt );
        points2.push_back ( keypoints_2[matches[i].trainIdx].pt );
    }

    Mat fundamental_matrix;
    fundamental_matrix = findFundamentalMat ( points1, points2, CV_FM_8POINT );

    Point2d principal_point ( 325.1, 249.7 ); // focal point, cx, cy
    double focal_length = 521; // fx, fy
    Mat essential_matrix;
    essential_matrix = findEssentialMat ( points1, points2, focal_length, principal_point );

    Mat homography_matrix;
    //                                                    ransacReprojThreshold
    homography_matrix = findHomography ( points1, points2, RANSAC, 3 );

    // E -> R|t (E = t^*R)
    recoverPose ( essential_matrix, points1, points2, R, t, focal_length, principal_point );
    return essential_matrix;
}
