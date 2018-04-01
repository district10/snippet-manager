MatrixXd A = MatrixXd::Random(100,100);
MatrixXd b = MatrixXd::Random(100,1);
{
    // universal: SVD
    cout << "\n\njacobiSvd (least square):\n" << A.jacobiSvd(ComputeThinU | ComputeThinV).solve(b).transpose() << endl;
}
{
    // fast: QR decomposition
    // There are three QR decomposition classes:
    //  -   HouseholderQR (no pivoting, so fast but unstable),
    //  -   ColPivHouseholderQR (column pivoting, thus a bit slower but more accurate) and
    //  -   FullPivHouseholderQR (full pivoting, so slowest and most stable)
    cout << "\n\nfullPivHouseHolderQr:\n" << A.fullPivHouseholderQr().solve(b).transpose() << endl;
}
{
    // normal equation, cholescky decomposition (LDLT)
    cout << "\n\nnormal equations (A^T*A * x = A^T * b):\n" << (A.transpose() * A).ldlt().solve(A.transpose() * b).transpose() << endl;
}
