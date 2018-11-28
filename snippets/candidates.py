# not in candidates
# if sys.version_info[:2] >= (3, 6):
if sys.version_info[:2] not in [(2, 6), (2, 7)] and \
        sys.version_info[:1] not in [(3, )]:
    sys.stderr.write("Sorry, only Python 2.7, and 3.x are supported "
                     "at this time.\n")
    exit(1)

from __future__ import print_function
import sys
from functools import partial

error = partial(print, file=sys.stderr)
print >> sys.stderr, 'spam'

