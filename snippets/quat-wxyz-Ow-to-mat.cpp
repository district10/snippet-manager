cv::Mat quat_wxyz_to_rotation(const std::vector<double> &q)
{
    double w = q[0], x = q[1], y = q[2], z = q[3];
    Eigen::Quaterniond q_(w, x, y, z);
    Eigen::Matrix3d R(q_);
    cv::Mat ret;
    eigen2cv(R, ret);
    return ret;
}

std::vector<double> toQuaternion(const cv::Mat &M)
{
    Eigen::Matrix<double, 3, 3> eigMat = toMatrix3d(M);
    Eigen::Quaterniond q(eigMat);

    std::vector<double> v(4);
    v[0] = q.w();
    v[1] = q.x();
    v[2] = q.y();
    v[3] = q.z();
    return v;
}

void Ow_quat_wxyz___to___Rt(const std::vector<double> Ow,
                            const std::vector<double> quat_wxyz, //
                            cv::Mat &R, cv::Mat &t)
{
    cv::Mat Ow_ = vec3(Ow[0], Ow[1], Ow[2]);
    quat_wxyz_to_rotation(quat_wxyz).copyTo(R);
    cv::Mat t_ = -R * Ow_;
    t_.copyTo(t);
}

void Rt___to___Ow_quat_wxyz(const cv::Mat &R, const cv::Mat &t, //
                            std::vector<double> &Ow,
                            std::vector<double> &quat_wxyz)
{
    cv::Mat Ow_ = -R.t() * t;
    Ow = vector<double>{Ow_.at<double>(0, 0), //
                        Ow_.at<double>(1, 0), //
                        Ow_.at<double>(2, 0)};
    quat_wxyz = toQuaternion(R);
}
