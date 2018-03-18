// C++: MatExpr Mat::inv(int method=DECOMP_LU) const¶
Mat pinvA=A.inv(DECOMP_SVD);
//          -   DECOMP_LU is the LU decomposition. The matrix must be non-singular.
//          -   DECOMP_CHOLESKY is the Cholesky LL^T decomposition for symmetrical positively
//              defined matrices only. This type is about twice faster than LU on big matrices.
//          -   DECOMP_SVD is the SVD decomposition. If the matrix is singular or even non-square,
//              the pseudo inversion is computed.
