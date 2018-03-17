Eigen::Matrix3d W = Eigen::Matrix3d::Zero();
for ( int i=0; i<N; i++ ) {
    W += Eigen::Vector3d ( q1[i].x, q1[i].y, q1[i].z ) * Eigen::Vector3d ( q2[i].x, q2[i].y, q2[i].z ).transpose();
}
