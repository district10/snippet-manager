import numpy as np

# numpy.arange([start, ]stop, [step, ]dtype=None)
for lon in np.arange(0, 180, 0.5):
    print "lon:{}, zone:{}".format(lon, int((lon + 180.0) / 6.0) + 1)
