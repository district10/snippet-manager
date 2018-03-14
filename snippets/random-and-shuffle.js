// 取元素 (random select/sample)
const sample = arr => arr[Math.floor(Math.random() * arr.length)];

// 打乱元素 (shuffle)
const shuffle = arr => arr.sort(() => Math.random() - 0.5);
