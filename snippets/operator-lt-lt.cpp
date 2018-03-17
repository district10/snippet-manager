// 1
cout << phone << endl;
// 2
(cout << phone) << endl;
// 3
operator<<(cout, phone).operator<<(endl);

static inline
std::ostream& operator << (std::ostream& out, const Mat& mtx) {
    return out << Formatter::get()->format(mtx);
}
