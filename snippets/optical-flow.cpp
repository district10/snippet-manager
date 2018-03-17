vector<cv::Point2f> next_keypoints, prev_keypoints;
for ( auto kp : keypoints ) prev_keypoints.push_back(kp);
vector<unsigned char> status;
vector<float> error;
cv::calcOpticalFlowPyrLK( last_color, color, prev_keypoints, next_keypoints, status, error );
