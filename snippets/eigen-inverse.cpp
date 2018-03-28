#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
   Matrix3f A;
   A << 1, 2, 1,
        2, 1, 0,
        -1, 1, 2;
   // 数学上 inverse 很好, 但数值线性系统中用分解更快. (小矩阵的话, 分解也没有公式快)
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "The determinant of A is " << A.determinant() << endl;
   cout << "The inverse of A is:\n" << A.inverse() << endl;
}
