std::vector<int> v1 = {1, 2, 3, 4, 5};
std::vector<int> v2 = {      3, 4, 5, 6, 7};
std::vector<int> dest1;

std::set_union(v1.begin(), v1.end(),
               v2.begin(), v2.end(),
               std::back_inserter(dest1));
