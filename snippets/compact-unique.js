// compact 就是去掉 falsy 的元素
const compact = (arr) => arr.filter(v => v);

// unique 就是 indexOf 和 lastIndexOf 一样的元素
const filterNonUnique = arr => arr.filter(i => arr.indexOf(i) === arr.lastIndexOf(i));
