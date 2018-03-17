#include <opencv2/core/eigen.hpp>
Eigen::Matrix<double, Dynamic, Dynamic> eigenTxR;
cv2eigen(txR, eigenTxR);
eigen2cv(R_, R);

// MatrixXd m = Eigen::Map<MatrixXd>(reinterpret_cast<double*>(a.data),a.rows,a.cols);
