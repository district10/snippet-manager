ifstream fin(filepath);
if (!fin) {
    // cerr << "error" << endl;
}
for (string line; getline(fin, line);) {
    istringstream iss(line);
    vector<double> T((istream_iterator<double>(iss)), istream_iterator<double>());
}

