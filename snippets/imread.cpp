cv::Mat img = cv::imread( IMAGE_INPUT_SRC /*, cv::IMREAD_COLOR*/ ); //  1
//      //! Imread flags
//      enum ImreadModes {
//             IMREAD_UNCHANGED            = -1,
//             IMREAD_GRAYSCALE            = 0,
//             IMREAD_COLOR                = 1,
//             IMREAD_ANYDEPTH             = 2,
//             IMREAD_ANYCOLOR             = 4,
//             IMREAD_LOAD_GDAL            = 8,
//             IMREAD_REDUCED_GRAYSCALE_2  = 16,
//             IMREAD_REDUCED_COLOR_2      = 17,
//             IMREAD_REDUCED_GRAYSCALE_4  = 32,
//             IMREAD_REDUCED_COLOR_4      = 33,
//             IMREAD_REDUCED_GRAYSCALE_8  = 64,
//             IMREAD_REDUCED_COLOR_8      = 65
//           };
if ( img.data == nullptr) {
    // ...
}
cv::imshow( "src", img );
img.release();
