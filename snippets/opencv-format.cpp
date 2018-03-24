// opencv 2
std::cout << cv::format(image, "numpy") << std::endl;

// opencv 3
std::cout << cv::format(image, cv::Formatter::FMT_NUMPY) << std::endl;
// FMT_DEFAULT
// FMT_MATLAB
// FMT_CSV
// FMT_PYTHON
// FMT_NUMPY
// FMT_C
