// 旋转向量使用 AngleAxis, 它底层不直接是Matrix，但运算可以当作矩阵（因为重载了运算符）
Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
Eigen::AngleAxisd rotation_vector ( M_PI/2, Eigen::Vector3d ( 0,0,1 ) );    //沿 Z 轴旋转 90 度
cout.precision(3);
cout << "rotation matrix =\n" << rotation_vector.matrix() <<endl;
// 也可以直接赋值
rotation_matrix = rotation_vector.toRotationMatrix();

Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles ( 2,1,0 );       // ZYX顺序，即roll pitch yaw顺序
cout << "yaw pitch roll = " << euler_angles.transpose() << endl;
