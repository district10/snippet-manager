Eigen::Matrix3d R = Eigen::AngleAxisd(M_PI/2, Eigen::Vector3d(0,0,1)).toRotationMatrix();

Sophus::SO3 SO3_R(R);                   // Sophus::SO(3)可以直接从旋转矩阵构造
Sophus::SO3 SO3_v( 0, 0, M_PI/2 );      // 亦可从旋转向量构造
Eigen::Quaterniond q(R);                // 或者四元数
Sophus::SO3 SO3_q( q );

// 输出SO(3)时，以so(3)形式输出
cout << "SO(3): " << SO3_R << endl;
