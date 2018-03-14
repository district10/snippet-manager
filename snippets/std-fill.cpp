std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

std::fill(v.begin(), v.end(), -1);

for (auto elem : v) {
    std::cout << elem << " ";   // -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
}
