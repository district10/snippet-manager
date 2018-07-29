static int i = 0;
auto rand256 = []() -> int { return int(rand() / double(RAND_MAX) * 255); };
int r = rand256(), g = rand256(), b = rand256();
for (const auto &pt : pts) {
    cout << "SHITME point " << ++i;
    cout << " " << pt[0] << " " << pt[1] << " " << pt[2];
    cout << " " << r << " " << g << " " << b << endl;
}
// sampling cubic curve
for (auto &p : params) {
    double h = param[12];
    for (double t = 0; t < h; t += 0.5) {
        double t2 = t * t;
        double t3 = t * t * t;
        double x = p[0] + p[1] * t + p[2] * t2 + p[3] * t3;
        double y = p[4] + p[5] * t + p[6] * t2 + p[7] * t3;
        double z = p[8] + p[9] * t + p[10] * t2 + p[11] * t3;
        cout << "SHITME samplept " << ++i;
        cout << " " << x << " " << y << " " << z;
        cout << " " << r << " " << g << " " << b << endl;
    }
}
