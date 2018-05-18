#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;
using namespace std;
int main()
{
    MatrixXd m = MatrixXd::Random(3,3);
    m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
    cout << "m =" << endl << m << endl;
    VectorXd v(3);
    v << 1, 2, 3;
    cout << "m * v =" << endl << m * v << endl;

    MatrixXf mat = MatrixXf::Random(2, 3);
    std::cout << mat << std::endl << std::endl;
    mat = (MatrixXf(2,2) << 0, 1, 1, 0).finished() * mat;
    std::cout << mat << std::endl;
}
