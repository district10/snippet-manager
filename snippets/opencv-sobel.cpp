cv::Sobel( imgGray, imgSobelX, // src -> dst
           CV_16S,             // ddepth
           1, 0, 3,            // dx, dy, ksize
           1, 1,               // scale, delta
           cv::BORDER_DEFAULT );
cv::Sobel( imgGray, imgSobelY, // src -> dst
           CV_16S,             // ddepth
           0, 1, 3,            // dx, dy, ksize
           1, 1,               // scale, delta
           cv::BORDER_DEFAULT );
cv::convertScaleAbs( imgSobelX, imgSobelAbsX );
cv::convertScaleAbs( imgSobelY, imgSobelAbsY );
cv::addWeighted( imgSobelAbsX, 0.5, imgSobelAbsY, 0.5, 0, imgSobel );
