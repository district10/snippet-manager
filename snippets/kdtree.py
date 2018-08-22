from scipy import spatial
tree = kspatial.KDTree(points)
dist = tree.query([pt], 1, 0, 2, thresh)[0][0]
indexes = tree.query_ball_point(pt, 0.5)
