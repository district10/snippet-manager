Sophus::SE3 SE3_Rt(R, t);
typedef Eigen::Matrix<double,6,1> Vector6d;
Vector6d se3 = SE3_Rt.log(); // [translation | rotation]
Sophus::SE3::hat(se3)<<endl;
Sophus::SE3::vee( Sophus::SE3::hat(se3) ).transpose();

Vector6d update_se3;
update_se3.setZero();
update_se3(0,0) = 1e-4d;
Sophus::SE3 SE3_updated = Sophus::SE3::exp(update_se3) * SE3_Rt;
SE3_updated.matrix();
