# mkdir: method 1
import os, errno

try:
    os.makedirs(directory)
except OSError as e:
    if e.errno != errno.EEXIST:
        raise

# mkdir: method 2
import os
if not os.path.exists(directory):
    os.makedirs(directory)
