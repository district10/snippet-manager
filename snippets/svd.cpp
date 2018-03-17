Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (m); // svd
cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;
