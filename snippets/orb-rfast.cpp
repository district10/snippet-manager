static int bit_pattern_31_[256*4] =
{
    8,-3, 9,5/*mean (0), correlation (0)*/,
    4,2, 7,-12/*mean (1.12461e-05), correlation (0.0437584)*/,
    -11,9, -8,2/*mean (3.37382e-05), correlation (0.0617409)*/,
    // ...
};

typedef Point_<int> Point2i;
typedef Point2i Point;

const int npoints = 512;
const Point* pattern0 = (const Point*)bit_pattern_31_;
std::copy(pattern0, pattern0 + npoints, std::back_inserter(pattern));
