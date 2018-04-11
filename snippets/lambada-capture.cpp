// 运行时捕获
void learn_lambda_func_1() {
    int value_1 = 1;
    auto copy_value_1 = [value_1] {
        return value_1;
    };
    value_1 = 100;
    auto stored_value_1 = copy_value_1();
    // 这时, stored_value_1 == 1, 而 value_1 == 100.
    // 因为 copy_value_1 在创建时就保存了一份 value_1 的拷贝
}
// 引用捕获
void learn_lambda_func_2() {
    int value_2 = 1;
    auto copy_value_2 = [&value_2] {
        return value_2;
    };
    value_2 = 100;
    auto stored_value_2 = copy_value_2();
    // 这时, stored_value_2 == 100, value_1 == 100.
    // 因为 copy_value_2 保存的是引用
}


// 捕获列表的最常用的四种形式可以是：
//  -   [] 空捕获列表
//  -   [name1, name2, ...] 捕获一系列变量
//  -   [&] 引用捕获, 让编译器自行推导捕获列表
//  -   [=] 值捕获, 让编译器执行推导应用列表
