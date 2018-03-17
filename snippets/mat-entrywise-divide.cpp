Mat ratio;
divide(txR, E, ratio);
cout << "entrywise divide: " << ratio << endl;

MatrixXf m(2,2), n(2, 2);
m << 1,2,3,4; n << 6,7,8,9;
cout << "entrywise divide: " << m.array() / n.array() << endl;
