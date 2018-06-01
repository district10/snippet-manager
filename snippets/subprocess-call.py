from subprocess import call
call(["ls", "-l"])

import os
ret = os.system("ls -l")
if ret != 0 :
    pass
