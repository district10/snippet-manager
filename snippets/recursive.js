// 拍扁, concat 如果接收到一个 obj, 就 push, 如果是一个 list, 就合并
const flatten = arr => arr.reduce((a, v) => a.concat(v), []);

// 有点好奇为啥要 [].concat(list) 而不直接用 list, 这是在获取拷贝?
const deepFlatten = arr => [].concat(...arr.map(v => Array.isArray(v) ? deepFlatten(v) : v));

// 如果要控制层数, 只能是多一个 flag, 然后每次递归的时候 check 一下
const flattenDepth = (arr, depth = 1) =>
  depth != 1 ? arr.reduce((a, v) => a.concat(Array.isArray(v) ? flattenDepth(v, depth - 1) : v), [])
  : arr.reduce((a, v) => a.concat(v), []);

// 尾递归不需要新开栈, 避免了爆栈, 通常加一个参数来存储
const factorial = n => n <= 1 ? 1 : n * factorial(n - 1);
const factorial = (n, ret=1) => n <= 1 ? ret : factorial(n - 1, n*ret);
