$ cat ~/bin/dvorak
#!/bin/bash

xmodmap ~/git/neo_keyboard_layout/neo4linux/dvorak.xmodmap
pkill xcape; xcape -e 'Control_L=Escape'

$ cat ~/bin/qwerty
#!/bin/bash

xmodmap ~/git/neo_keyboard_layout/neo4linux/qwerty.xmodmap
