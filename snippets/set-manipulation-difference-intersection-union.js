// a\b
const difference = (a, b) => { const s = new Set(b); return a.filter(x => !s.has(x)); };

// a∩b
const intersection = (a, b) => { const s = new Set(b); return a.filter(x => s.has(x)); };

// a∪b
const union = (a, b) => Array.from(new Set([...a, ...b]));
