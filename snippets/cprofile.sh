python -m cProfile

import cProfile
import re
cProfile.run('re.compile("foo|bar")')

