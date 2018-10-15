# http://python-future.org/compatible_idioms.html
# python2 python3 compatible code

from __future__ import print_function    # (at top of module)
import future        # pip install future
import builtins      # pip install future
import past          # pip install future
import six           # pip install six

print('Hello')
print('Hello', 'Guido')
print('Hello', file=sys.stderr)
