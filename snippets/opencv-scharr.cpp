cv::Rect rectangle;
cv::cvtColor( imgSrc, imgSrc, cv::COLOR_BGR2GRAY );
cv::Laplacian( imgSrc, imgLaplace, CV_16S, 3, 1, 0, cv::BORDER_DEFAULT );
cv::convertScaleAbs( imgLaplace, imgLaplace );

// scharr
cv::Scharr( imgSrc, imgGradX, CV_16S, 1, 0, 1, 0, cv::BORDER_DEFAULT );
cv::Scharr( imgSrc, imgGradY, CV_16S, 0, 1, 1, 0, cv::BORDER_DEFAULT );
cv::convertScaleAbs( imgGradX, imgGradX );
cv::convertScaleAbs( imgGradY, imgGradY );
cv::addWeighted( imgGradX, 0.5, imgGradY, 0.5, 0, imgScharr );
