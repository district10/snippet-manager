# Ow = [x, y, z], quat = [w, x, y, z]
def Ow_quat_wxyz___to___Rt(Ow, quat_wxyz):
    R = transforms3d.quaternions.quat2mat(quat_wxyz)
    t = -R.dot(Ow)
    return [R, t]


def from_R_t(R, t):
    return np.hstack((np.copy(R), np.copy(t).reshape(3, 1)))


def from_T(T):
    R = T[:3, :3]
    t = T[:, 3]
    return [R, t]


def inv_T(T):
    R, t = from_T(T)
    t = -R.T.dot(t)
    return from_R_t(R.T, t)


def apply_T(T, p):
    return T.dot(np.hstack((p, [1.0])))
