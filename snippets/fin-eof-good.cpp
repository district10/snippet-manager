ifstream fin(path);
if (!fin) return false;

while (!fin.eof() && fin.good()) {
    // read from fin
}
