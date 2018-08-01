#include <bitset>
...

char a = -58;
std::bitset<8> x(a);
std::cout << x;

// print int as binary
short c = -315;
std::bitset<16> y(c);
std::cout << y;
