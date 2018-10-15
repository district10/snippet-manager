import transforms3d
T = np.array(data["T"]).reshape(4, 4)
y, r, p = [math.degrees(r)  for r in transforms3d.euler.mat2euler(T[:3, :3], "szyx")]
