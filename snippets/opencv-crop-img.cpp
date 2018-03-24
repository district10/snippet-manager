void getRotRectImg( cv::RotatedRect rr, Mat &img, Mat &dst ) {
    Mat m(2,3,CV_64FC1);
    float ang=rr.angle*CV_PI/180.0;
    m.at<double>(0,0)=cos(ang);
    m.at<double>(1,0)=sin(ang);
    m.at<double>(0,1)=-sin(ang);
    m.at<double>(1,1)=cos(ang);
    m.at<double>(0,2)=rr.center.x;
    m.at<double>(1,2)=rr.center.y;
    myGetQuadrangleSubPix(img,dst,m);
}

void myGetQuadrangleSubPix(const Mat& src, Mat& dst,Mat& m )
{
    CV_Assert( src.channels() == dst.channels() );

    cv::Size win_size = dst.size();
    double matrix[6];
    cv::Mat M(2, 3, CV_64F, matrix);
    m.convertTo(M, CV_64F);
    double dx = (win_size.width - 1)*0.5;
    double dy = (win_size.height - 1)*0.5;
    matrix[2] -= matrix[0]*dx + matrix[1]*dy;
    matrix[5] -= matrix[3]*dx + matrix[4]*dy;

    if( src.depth() == CV_8U && dst.depth() == CV_32F ) {
        getQuadrangleSubPix_8u32f_CnR( src.data, src.step, src.size(),
                (float*)dst.data, dst.step, dst.size(),
                matrix, src.channels());
        // todo
    } else {
        CV_Assert( src.depth() == dst.depth() );
        cv::warpAffine(src, dst, M, dst.size(),
                cv::INTER_LINEAR + cv::WARP_INVERSE_MAP,
                cv::BORDER_REPLICATE);
    }
}

