template<typename T>
bool fpScanf(FILE *fp, const char *format, T *value) {
    return fscanf(fp, format, value) != 1;
}

template<typename T, typename U>
auto add2(T x, U y) -> decltype(x+y){
    return x + y;
}

// c++14
template<typename T, typename U>
auto add3(T x, U y){
    return x + y;
}

#include <iostream>

template<typename T>
auto print_type_info(const T& t) {
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}
int main() {
    std::cout << print_type_info(5) << std::endl;
    std::cout << print_type_info(3.14) << std::endl;
}
