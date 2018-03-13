FILE *fp = fopen(filepath, "r");
if (!fp) {
    // fprintf(stderr, ...);
}
double t, tx, ty, tz, qx, qy, qz, qw;
while (8 == fscanf(fp, "%lf %lf %lf %lf %lf %lf %lf %lf", &t, &tx, &ty, &tz, &qx, &qy, &qz, &qw)) {
    vector<double> T = {t, tx, ty, tz, qx, qy, qz, qw};
}
fclose(fp);
