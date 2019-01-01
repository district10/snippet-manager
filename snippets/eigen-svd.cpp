Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);

cout << "U*S*V^T - A:\n"
    << svd.matrixU() * svd.singularValues().asDiagonal() * svd.matrixV().transpose() - A
    << endl;
