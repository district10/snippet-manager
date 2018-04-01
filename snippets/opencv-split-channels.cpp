Mat img_yuv;
cvtColor(img, img_yuv, CV_BGR2YCrCb); // convert image to YUV color space.
                                      // The output image will be created automatically
vector<Mat> planes;                   // Vector is template vector class, similar to STL's vector.
                                      // It can store matrices too.
split(img_yuv, planes);               // split channels of the image into separate color planes
