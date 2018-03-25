QImage Utils::Mat2QImage( const cv::Mat &mat ) {
    return QImage( (uchar*)mat.data,
                   mat.cols, mat.rows, mat.step,
                   QImage::Format_RGB888 );
}

cv::Mat Utils::QImage2Mat( const QImage &qimg ) {
    cv::Mat mat( qimg.height(), qimg.width(), CV_8UC3, (uchar*)qimg.bits(), qimg.bytesPerLine() );
    cvtColor( mat, mat, CV_BGR2RGB );
    return mat;
}
