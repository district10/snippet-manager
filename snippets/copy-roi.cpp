cv::Mat img_show ( color.rows*2, color.cols, CV_8UC3 );
prev_color.copyTo ( img_show ( cv::Rect ( 0,0,color.cols, color.rows ) ) );     // copy src img to roi of dst img
color.copyTo ( img_show ( cv::Rect ( 0,color.rows,color.cols, color.rows ) ) );
