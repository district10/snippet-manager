Tracking::Tracking( ...string &strSettingPath, ...)
    : mState(NO_IMAGES_YET),
    , mfSettings(strSettingPath, cv::FileStorage::READ)
{
    float fx = mfSettings["Camera.fx"];
    float fy = mfSettings["Camera.fy"];
    float cx = mfSettings["Camera.cx"];
    float cy = mfSettings["Camera.cy"];

    cv::Mat K = cv::Mat::eye(3,3,CV_32F);
    K.at<float>(0,0) = fx; K.at<float>(0,2) = cx;
    K.at<float>(1,1) = fy; K.at<float>(1,2) = cy;
    K.copyTo(mK);

    cv::Mat DistCoef(4,1,CV_32F);
    DistCoef.at<float>(0) = mfSettings["Camera.k1"];
    DistCoef.at<float>(1) = mfSettings["Camera.k2"];
    DistCoef.at<float>(2) = mfSettings["Camera.p1"];
    DistCoef.at<float>(3) = mfSettings["Camera.p2"];
    const float k3 = mfSettings["Camera.k3"];
    if(k3!=0) {
        DistCoef.resize(5);
        DistCoef.at<float>(4) = k3;
    }
    DistCoef.copyTo(mDistCoef);

    mbf = mfSettings["Camera.bf"]; // z = fb/d

    float fps = mfSettings["Camera.fps"];
    if(fps==0) { fps=30; } // default

    // Max/Min Frames to insert keyframes and to check relocalisation
    mMinFrames = 0;
    mMaxFrames = fps;
    ...
}
