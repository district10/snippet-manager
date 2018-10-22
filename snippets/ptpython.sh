python3 -m pip install ptpython
python3 -m pip install ipython

import sys
try:
    from ptpython.repl import embed
except ImportError:
    print("ptpython is not available: falling back to standard prompt")
else:
    sys.exit(embed(globals(), locals()))

