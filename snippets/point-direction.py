import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d, Axes3D

def draw_points(points):
    fig = plt.figure()
    ax = Axes3D(fig)

    # 绘制虚拟的三维 bounding box，保证三轴成比例
    minpt = np.min(points[:, :3], axis=0)
    maxpt = np.max(points[:, :3], axis=0)
    max_range = np.array([maxpt[0] - minpt[0], maxpt[1] - minpt[1], maxpt[2] - minpt[2]]).max()
    Xb = 0.5 * max_range * np.mgrid[-1:2:2, -1:2:2, -1:2:2][0].flatten() + 0.5 * (maxpt[0] + minpt[0])
    Yb = 0.5 * max_range * np.mgrid[-1:2:2, -1:2:2, -1:2:2][1].flatten() + 0.5 * (maxpt[1] + minpt[1])
    Zb = 0.5 * max_range * np.mgrid[-1:2:2, -1:2:2, -1:2:2][2].flatten() + 0.5 * (maxpt[2] + minpt[2])
    for xb, yb, zb in zip(Xb, Yb, Zb):
        ax.plot([xb], [yb], [zb], 'w')
    ax.scatter(points[:, 0], points[:, 1], points[:, 2], c='y')
    ax.quiver(points[:, 0], points[:, 1], points[:, 2],
              points[:, 3], points[:, 4], points[:, 5], length=0.05, normalize=True)
    plt.show()
