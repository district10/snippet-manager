// common opencv canvas opration, draw opencv
cv::Scalar color(0, 240, 0);
cv::circle(img, centerPoint, radius, color, thickness);
cv::line ( img_show, pt1, pt2, color, thickness );
srcImg.copyTo ( img ( cv::Rect (x,y,w,h) ) );
