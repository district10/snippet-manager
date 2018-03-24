// compute pseudo-inverse of A, equivalent to A.inv(DECOMP_SVD)
SVD svd(A); // svd(A) = u * diag(w) * vt
// pinvA - p-inv-A, psedu-inverse-of-A
Mat pinvA = svd.vt.t()*Mat::diag(1./svd.w)*svd.u.t();

// compute the new vector of parameters in the Levenberg-Marquardt algorithm
x -= (A.t()*A + lambda*Mat::eye(A.cols,A.cols,A.type())).inv(DECOMP_CHOLESKY)*(A.t()*err);

// sharpen image using "unsharp mask" algorithm
Mat blurred; double sigma = 1, threshold = 5, amount = 1;
GaussianBlur(img, blurred, Size(), sigma, sigma);
Mat lowConstrastMask = abs(img - blurred) < threshold;
Mat sharpened = img*(1+amount) + blurred*(-amount);
img.copyTo(sharpened, lowContrastMask);

// svd decomp
cv::Mat u,w,vt;
cv::SVDecomp(A,w,u,vt,cv::SVD::MODIFY_A | cv::SVD::FULL_UV);
cv::Mat Fpre = vt.row(8).reshape(0, 3); // v的最后一列
cv::SVDecomp(Fpre,w,u,vt,cv::SVD::MODIFY_A | cv::SVD::FULL_UV);
w.at<float>(2)=0; // 秩2约束，将第3个奇异值设为0
return  u*cv::Mat::diag(w)*vt;
