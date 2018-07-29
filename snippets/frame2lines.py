# n points
def lerp_line(pt0, pt1, n):
    pts = []
    for i in range(n + 1):
        t = i / float(n)
        pt = pt0 * t + pt1 * (1.0 - t)
        pts.append(pt)
    return pts


def pole_to_lines(pt0, pt1, color=[0, 255, 0], n=20):
    lines = []
    pts = lerp_line(pt0, pt1, n)
    for pt in pts:
        lines.append([pt[0], pt[1], pt[2], color[0], color[1], color[2]])
    return lines


def frame_to_lines(Tcw, n=5):
    Twc = inv_T(Tcw)
    p000 = np.array([0.0, 0.0, 0.0])
    p100 = np.array([1.0, 0.0, 0.0])
    p010 = np.array([0.0, 1.0, 0.0])
    p001 = np.array([0.0, 0.0, 1.0])
    p100 /= 10.0
    p010 /= 10.0
    p001 /= 10.0
    xs = lerp_line(p000, p100, n)
    ys = lerp_line(p000, p010, n)
    zs = lerp_line(p000, p001, n)
    wxs = [apply_T(Twc, p) for p in xs]
    wys = [apply_T(Twc, p) for p in ys]
    wzs = [apply_T(Twc, p) for p in zs]
    lines = []
    Ow = apply_T(Twc, p000)
    lines.append([Ow[0], Ow[1], Ow[2], 255, 255, 255])
    for p in wxs[1:]:
        lines.append([p[0], p[1], p[2], 255, 0, 0])
    for p in wys[1:]:
        lines.append([p[0], p[1], p[2], 0, 255, 0])
    for p in wzs[1:]:
        lines.append([p[0], p[1], p[2], 0, 0, 255])
    return lines
