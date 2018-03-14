cv::floodFill( imgFloodFill,                // input&output
               cv::Point(345,234),          // seed point
               cv::Scalar(155, 255,55),     // new value
               &ccomp,                      //
               cv::Scalar(20, 20, 20),      // lo diff
               cv::Scalar(20, 20, 20) );    // up diff
