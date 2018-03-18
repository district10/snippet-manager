Mat D (A, Rect(10, 10, 100, 100) ); // using a rectangle
Mat E = A(Range::all(), Range(1,3)); // using row and column boundaries

Mat F = A.clone();
Mat G;
A.copyTo(G);

Mat M(2,2, CV_8UC3, Scalar(0,0,255));
Mat E = Mat::eye(4, 4, CV_64F);
Mat O = Mat::ones(2, 2, CV_32F);
Mat Z = Mat::zeros(3,3, CV_8UC1);
Mat C = (Mat_<double>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
Mat RowClone = C.row(1).clone();

Mat R = Mat(3, 2, CV_8UC3);
randu(R, Scalar::all(0), Scalar::all(255));

cout << "R (default) = " << endl <<        R           << endl << endl;
cout << "R (python)  = " << endl << format(R,"python") << endl << endl;
cout << "R (numpy)   = " << endl << format(R,"numpy" ) << endl << endl;

vector<Point2f> vPoints(20);
for (size_t i = 0; i < vPoints.size(); ++i) {
    vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
}

Scalar intensity = img.at<uchar>(y, x);
Scalar intensity = img.at<uchar>(Point(x, y));

// b,g,r imread default
Vec3b intensity = img.at<Vec3b>(y, x);
uchar blue = intensity.val[0];
uchar green = intensity.val[1];
uchar red = intensity.val[2];

vector<Point2f> points;
//... fill the array
Mat pointsMat = Mat(points);
