cv::FileStorage fs( qPrintable( filename ) , cv::FileStorage::READ );
fs["width"] >> config.width;
fs["length"] >> config.length;
fs.release();

cv::FileStorage fs( qPrintable( filename ) , cv::FileStorage::WRITE );
fs << "width" << config.width
   << "length" << config.length;
fs.release();
