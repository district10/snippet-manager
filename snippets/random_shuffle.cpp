// C++98
#include <algorithm>
std::random_shuffle(cards_.begin(), cards_.end());

// C++11 onwards
auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); // std::chrono::system_clock::now().time_since_epoch().count();
auto rng = std::default_random_engine(seed);
shuffle(begin(cards_), end(cards_), rng);
