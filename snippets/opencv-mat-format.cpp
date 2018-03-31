//    cout.setf( std::ios::fixed, std::ios::floatfield );
//    cout.precision(2);

Mat conv(images.size(), images.size(), CV_64F);
conv.at<double>(i,j) = conv.at<double>(j,i) = score;

cv::Ptr<cv::Formatter> formatMat=Formatter::get(cv::Formatter::FMT_DEFAULT);
formatMat->set64fPrecision(3);
formatMat->set32fPrecision(3);
cout << formatMat->format(conv) << endl;
