// reduce 出一个数值
const countOccurrences = (arr, value) => arr.reduce((a, v) => v === value ? a + 1 : a + 0, 0);

// reduce 出一个 list
const fibonacci = n =>
  Array(n).fill(0).reduce((acc, val, i) => acc.concat(i > 1 ? acc[i - 1] + acc[i - 2] : i), []);

// reduce 出一个 object
const objectFromPairs = arr => arr.reduce((a, v) => (a[v[0]] = v[1], a), {});

// 利用 reduce 的第三个参数 index
const groupBy = (arr, func) =>
  arr.map(typeof func === 'function' ? func : val => val[func])
    .reduce((acc, val, i) => { acc[val] = (acc[val] || []).concat(arr[i]); return acc; }, {});

// key in obj, 还用了 (exp1, exp2, ..., expN) 返回值为 expN
const pick = (obj, arr) =>
  arr.reduce((acc, curr) => (curr in obj && (acc[curr] = obj[curr]), acc), {});

// 如果 reduce 没有第二个参数, 会从第 1,2 个开始 reduce: arr.reduce(callback[, initialValue])
const pipe = (...fns) => fns.reduce((f, g) => (...args) => g(f(...args)));
/*
const add5 = x => x + 5
const multiply = (x, y) => x * y
const multiplyAndAdd5 = pipe(multiply, add5)
multiplyAndAdd5(5, 2) -> 15
*/
