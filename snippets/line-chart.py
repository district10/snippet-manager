# python line chart
lines = []
with open(input) as f:
    lines = f.readlines()

xs, ys, zs, ds = [], [], [], []
for idx, line in enumerate(lines):
    if not line.startswith(prefix):
        continue
    line = line[len(prefix):].strip()
    if not line:
        continue
    nums = line.split()
    # print nums
    x, y, z = float(nums[0][1:-1]), float(nums[1][0:-1]), float(nums[2][0:-1])
    d = math.sqrt(x*x + y*y + z*z)
    xs.append(x)
    ys.append(y)
    zs.append(z)
    ds.append(d)

xs, ys, zs, ds = sorted(xs), sorted(ys), sorted(zs), sorted(ds)

plt.subplot(411)
plt.plot(range(len(xs)), xs, color=[1.0, 0.0, 0.0])
plt.subplot(412)
plt.plot(range(len(ys)), ys, color=[0.0, 1.0, 0.0])
plt.subplot(413)
plt.plot(range(len(zs)), zs, color=[0.0, 0.0, 1.0])
plt.subplot(414)
plt.plot(range(len(ds)), sorted(ds), color=[0.0, 0.0, 0.0])
plt.subplots_adjust(hspace=0.5)
plt.show()
