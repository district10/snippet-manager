// Ax=b
LLT<Matrix2f> llt;
llt.compute(A);
llt.solve(b);
