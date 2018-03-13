#include <sophus/se3.h>

vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> posesGroundTruth;

double t, tx, ty, tz, qx, qy, qz, qw;

if ( !freopen( groudtruth_file.c_str(), "r", stdin ) ) { return -1; }
while( 8 == scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &t, &tx, &ty, &tz, &qx, &qy, &qz, &qw) ) {
    Eigen::Quaterniond q = Eigen::Quaterniond (qw, qx, qy, qz);  q.normalize();
    Eigen::Vector3d t(tx, ty, tz);
    Sophus::SE3 SE3( q, t );
    posesGroundTruth.push_back(SE3);
}

double sum = 0.0;
for (int i = 0; i < posesEstimated.size(); i++) {
    auto se3_actual = posesEstimated[i];
    auto se3_primal = posesGroundTruth[i];
    auto v3 = (se3_actual.inverse() * se3_primal).log();
    sum += v3.transpose() * v3;
}
cout << sqrt(sum / posesEstimated.size()) << endl;
