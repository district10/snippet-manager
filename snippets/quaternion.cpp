Eigen::Quaterniond q(w, x, y, z); q.normalize();
Eigen::Isometry3d T(q);
T.pretranslate(Eigen::Vector3d(x, y, z));

Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
T1_cw.rotate ( q );
T1_cw.pretranslate ( Eigen::Vector3d (...) );

poses.push_back( T );
