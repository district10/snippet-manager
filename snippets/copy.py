# list.copy() or li[:]
>>> x = [2,3]
>>> y = x[:]
>>> y[0] = 5
>>> x
[2, 3]
>>> y = x
>>> y
[2, 3]
>>> y[0] = 5
>>> x
[5, 3]

# Slicing builtin types returns a copy but that's not universal. Notably,
# slicing NumPy arrays returns a view that shares memory with the original
