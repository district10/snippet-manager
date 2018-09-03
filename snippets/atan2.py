def get_atan2(T_enu_ecef, Tcw, Ow, center_xyz):
    """
                 ^ Y (north)
               90|      45
                 |
         170     |
        ---------+----------> X (east)
        -170     |
                 |
              -90|    -45
                 |
    """
    pt1 = _util.apply_T(T_enu_ecef, center_xyz + _util.inv_T(Tcw).dot([0, 0, 10, 1]))
    pt0 = _util.apply_T(T_enu_ecef, center_xyz + Ow)
    delta = pt1 - np.array(pt0)
    return math.degrees(math.atan2(delta[1], delta[0]))
