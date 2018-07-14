# Linear algebra (numpy.linalg)
#       https://docs.scipy.org/doc/numpy/reference/routines.linalg.html
unit = v / np.linalg.norm(v)

z = np.cross(x, y)
z = z / np.linalg.norm(z)

#   0
#  /S\
# 1---2
def triangle_area(p0, p1, p2):
    v1 = p1 - p0
    v2 = p2 - p0
    return np.linalg.norm(np.cross(v1, v2))
