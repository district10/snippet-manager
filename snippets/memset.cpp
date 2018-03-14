// 别人用 memset(buf, -1, sizeof(buf)) 来初始化 buf，你用 -2 可不是 -2 啊！这涉及到 two’s compliment 编码。
// 另一个不符合直觉的是 int buf = { 0 }; 确实会把所有元素初始化为 0，但是 int buf = { 3 }; 只回初始化第一个元素为 3，其它都是 0…… 至少在我的 gcc 和 g++ 上都是如此。
memset( m, -1, sizeof(m) );
