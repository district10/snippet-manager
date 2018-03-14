#include <vector>
#include <iostream>

int main( )
{
    std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : c) {
        std::cout << i << " ";                  // 0 1 2 3 4 5 6 7 8 9
    }
    std::cout << '\n';

    c.erase(c.begin());

    for (auto &i : c) {
        std::cout << i << " ";                  // 1 2 3 4 5 6 7 8 9
    }
    std::cout << '\n';

    c.erase(c.begin()+2, c.begin()+5);

    for (auto &i : c) {
        std::cout << i << " ";                  // 1 2 6 7 8 9
    }
    std::cout << '\n';
}
