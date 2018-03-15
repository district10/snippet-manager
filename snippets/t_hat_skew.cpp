// t^ (t hat), cross product, t skew
Mat t_x = ( Mat_<double> ( 3,3 ) <<
        0,                      -t.at<double> ( 2,0 ),     t.at<double> ( 1,0 ),
        t.at<double> ( 2,0 ),      0,                      -t.at<double> ( 0,0 ),
        -t.at<double> ( 1.0 ),   t.at<double> ( 0,0 ),      0 );
