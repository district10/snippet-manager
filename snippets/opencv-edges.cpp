// opencv edges
cv::Mat element = cv::getStructuringElement( cv::MORPH_RECT, cv::Size(15, 15) );
cv::dilate(         imgSrc, imgDilate, element );
cv::erode(          imgSrc, imgEroded, element );
cv::blur(           imgSrc, imgBlurred, cv::Size(7, 7) );
cv::Canny(          imgSrc, imgEdge, 3, 9, 3 );
cv::boxFilter(      imgSrc, imgBox, -1, cv::Size(5, 5) );
cv::medianBlur(     imgSrc, imgMedian, 7 );
//                     src      dst  sigmaColor sigmaSpace borderType
cv::bilateralFilter( imgSrc, imgBilateral, 25, 25*2, 25/2 );

cv::morphologyEx( imgSrc, imgMorphDilate,    cv::MORPH_DILATE,    element );
cv::morphologyEx( imgSrc, imgMorphErode,     cv::MORPH_ERODE,     element );
cv::morphologyEx( imgSrc, imgMorphOpen,      cv::MORPH_OPEN,      element );
cv::morphologyEx( imgSrc, imgMorphClose,     cv::MORPH_CLOSE,     element );
cv::morphologyEx( imgSrc, imgMorphGradient,  cv::MORPH_GRADIENT,  element );
cv::morphologyEx( imgSrc, imgMorphTophat,    cv::MORPH_TOPHAT,    element );
cv::morphologyEx( imgSrc, imgMorphBlackhat,  cv::MORPH_BLACKHAT,  element );
