#include <random>

#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <climits>

int main() {
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};

    auto rand = std::bind(std::uniform_int_distribution<>(0, UCHAR_MAX), std::mt19937(seed));

    std::generate_n(std::ostream_iterator<int>(std::cout," "), 25, rand);
}
