ifstream fin(filepath);
for (string line; getline(fin, line);) {
    istringstream iss(line);
    vector<double> T((istream_iterator<double>(iss)), istream_iterator<double>());
}

