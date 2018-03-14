// pyramid, resize, resample
cv::resize( imgSrc, imgResize,
            cv::Size(imgSrc.rows/2,imgSrc.cols/2),
            0.0, 0.0,
            cv::INTER_AREA );               // interpolation method
cv::pyrUp( imgSrc, imgPyrUp,
           cv::Size(imgSrc.rows*2,imgSrc.cols*2) );
           // cv::BORDER_REPLICATE );       // border type, assert failed!
cv::pyrDown( imgSrc, imgPyrDown,
           cv::Size(imgSrc.rows/2,imgSrc.cols/2) );
