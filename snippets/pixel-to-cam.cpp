Point2d pixel2cam ( const Point2d& p, const Mat& K ) {
    return Point2d (
                   //                 cx              fx
               ( p.x - K.at<double> ( 0,2 ) ) / K.at<double> ( 0,0 ),
                   //                 cy              fy
               ( p.y - K.at<double> ( 1,2 ) ) / K.at<double> ( 1,1 )
           );
}
