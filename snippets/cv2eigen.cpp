#include <Eigen/Core>
#include <Eigen/Dense>
#include <opencv2/core/eigen.hpp>
#include <opencv2/opencv.hpp>

#include "Utils.h"
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    cv::Mat cv_mat1 = (cv::Mat_<double>(3, 1) << 1, 2, 3), cv_mat2;
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> eigen_mat;

    cv::cv2eigen(cv_mat1, eigen_mat);
    eigen2cv(eigen_mat, cv_mat2);
    cout << "cv mat: " << cv_mat1.t() << " --> "              //
         << "eigen mat: " << eigen_mat.transpose() << " --> " //
         << "cv mat2: " << cv_mat2.t()                        //
         << endl;

    // MatrixXd m = Eigen::Map<MatrixXd>(reinterpret_cast<double*>(a.data),a.rows,a.cols);

    return 0;
}
