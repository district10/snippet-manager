$ pkg-config --modversion --libs opencv
3.4.1

$ pkg-config --libs opencv
-L/usr/local/lib -lopencv_superres -lopencv_stitching -lopencv_shape -lopencv_dnn -lopencv_videostab -lopencv_calib3d -lopencv_video -lopencv_photo -lopencv_objdetect -lopencv_ml -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lopencv_flann -lopencv_core

$ pkg-config --cflags opencv
-I/usr/local/include/opencv -I
