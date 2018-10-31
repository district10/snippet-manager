# calculate how long per longitude/latitude
def calculate_radius(ref_lat):
    a = 6378137
    f = 1 / 298.257223563
    b = a * (1 - f)
    e1_2 = f + f * b / a
    phi = math.radians(ref_lat)
    sinphi2 = math.sin(phi) ** 2
    m = a * (1 - e1_2) / ((1 - e1_2 * sinphi2) ** 1.5)
    n = a / math.sqrt(1 - e1_2 * sinphi2)
    r = n * math.cos(phi)
    # m: y direction
    # r: x direction
    return m, n, r
