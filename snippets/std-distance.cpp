std::vector<int> v{ 3, 1, 4 };
std::cout << "distance(first, last) = "
          << std::distance(v.begin(), v.end()) << '\n' // 3
          << "distance(last, first) = "
          << std::distance(v.end(), v.begin()) << '\n'; // -3
