std::nullptr_t p;
p = NULL;
p = 0;

// Unlike in NULL, the size of nullptr_t is fixed.
assert(sizeof(std::nullptr_t) == sizeof(void*));
// sizeof(NULL) 等于 sizeof(0)，估计和 int 的长度一样。
