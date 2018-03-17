for ( DMatch m: matches ) {
    Point2d pt1 = pixel2cam ( keypoints_1[ m.queryIdx ].pt, K );
    Mat y1 = ( Mat_<double> ( 3,1 ) << pt1.x, pt1.y, 1 );
    Point2d pt2 = pixel2cam ( keypoints_2[ m.trainIdx ].pt, K );
    Mat y2 = ( Mat_<double> ( 3,1 ) << pt2.x, pt2.y, 1 );
    Mat d = y2.t() * t_x * R * y1;
    cout << "epipolar constraint = " << d << endl;
}
