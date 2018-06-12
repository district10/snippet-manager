// stod (c++11) example, atol, atof
#include <iostream>   // std::cout
#include <string>     // std::string, std::stod

int main ()
{
  std::string orbits ("365.24 29.53");
  std::string::size_type sz;     // alias of size_t

  double earth = std::stod (orbits,&sz);
  double moon = std::stod (orbits.substr(sz));
  std::cout << "The moon completes " << (earth/moon) << " orbits per Earth year.\n";
  return 0;
}
