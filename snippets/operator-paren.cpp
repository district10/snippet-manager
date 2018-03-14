struct Sum {
    Sum(): sum{0} { }
    void operator()(int n) { sum += n; }
    int sum;
};

std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });

// calls Sum::operator() for each number
Sum s = std::for_each(nums.begin(), nums.end(), Sum());

for (auto const &n : nums) {
    std::cout << ' ' << n;
}
