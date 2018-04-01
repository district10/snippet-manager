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

/////////////////
QImage cvMat2QImage(const cv::Mat& mat) {
    if(mat.type() == CV_8UC1) {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for(int i = 0; i < 256; i++) {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++) {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    } else if(mat.type() == CV_8UC3) {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    } else if(mat.type() == CV_8UC4) {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    } else {
        return QImage();
    }
}

cv::Mat QImage2cvMat(QImage image) {
    cv::Mat mat;
    switch(image.format()) {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine()); break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB); break;
    case QImage::Format_Indexed8:
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine()); break;
    }
    return mat;
}
