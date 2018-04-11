#include <iostream>

using foo = void(int); // 定义函数指针, using 的使用见上一节中的别名语法
void functional(foo f) {
    f(1);
}

int main() {
    auto f = [](int value) {
        std::cout << value << std::endl;
    };
    functional(f); // 函数指针调用
    f(1); // lambda 表达式调用
    return 0;
}
