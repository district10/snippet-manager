import transforms3d
import numpy as np
import math

def random_R(rx, ry, rz):
    return transforms3d.euler.euler2mat(*[math.radians(x) for x in [rx, ry, rz]], 'rzyx')

def inv_T1(T):
    return np.column_stack((T[:3, :3].T, -T[:3, :3].T.dot(T[:3, 3]))) # inverse

def inv_T2(T):
    return np.linalg.inv(np.row_stack((T, [0, 0, 0, 1])))[:3, :]

def test(inv=inv_T1):
    euler = np.random.random(3) * 50
    R = random_R(*euler)
    T = np.eye(3, 4)
    T[:3, :3] = R
    T[:3, 3] = np.random.random(3) * 100
    print('\nT is:\n', T)
    print('T.inv is:\n', inv(T))
    if True:
        diff = inv_T1(T) - inv_T2(T)
        print('diff is:\n', diff)

if __name__ == '__main__':
    np.set_printoptions(suppress=True)
    import timeit
    print(timeit.timeit('test()', setup='from __main__ import test', number=1000))
