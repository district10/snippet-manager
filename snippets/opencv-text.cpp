cv::Mat imText = cv::Mat(im.rows+textSize.height+10,im.cols,im.type());
im.copyTo(imText.rowRange(0,im.rows).colRange(0,im.cols));
imText.rowRange(im.rows,imText.rows) = cv::Mat::zeros(textSize.height+10,im.cols,im.type());
cv::putText(imText,s.str(),cv::Point(5,imText.rows-5),cv::FONT_HERSHEY_PLAIN,1,cv::Scalar(255,255,255),1,8);
