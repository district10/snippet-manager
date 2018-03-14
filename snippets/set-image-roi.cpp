cvSetImageROI( img, cvRect(x,y,w,h) );
cvSetImageCOI( img, 0 );

// both by reference
cv::Mat roi = img( cv::Rect(x,y,w,h) );
cv::Mat roi = img( cv::Range(y,y+dy), cv::Range(x,x+dx) );
