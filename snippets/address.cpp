#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdint>

std::string address(const uintptr_t &addr) {
    std::stringstream ss;
    ss << "0x" << std::setfill('0') << std::setw(sizeof(uintptr_t) * 2) << std::hex << addr;
    return ss.str();
}

template<typename T>
std::string address(const T *obj) {
    return address(reinterpret_cast<uintptr_t>(obj));
}

using namespace std;

int main(int argc, char **argv)
{
    // print address as hex
    int *x = new int(5);
    cout << address(x) << endl;
}
