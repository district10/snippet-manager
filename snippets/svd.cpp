Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (m); // svd
cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;

Eigen::JacobiSVD<Eigen::Matrix3d> svd ( W, Eigen::ComputeFullU|Eigen::ComputeFullV );
Eigen::Matrix3d U = svd.matrixU();
Eigen::Matrix3d V = svd.matrixV();

Eigen::Matrix3d R_ = U* ( V.transpose() );
// P1 = R*P2 + t, t = P1 - R*P2
Eigen::Vector3d t_ = Eigen::Vector3d ( p1.x, p1.y, p1.z ) - R_ * Eigen::Vector3d ( p2.x, p2.y, p2.z );
