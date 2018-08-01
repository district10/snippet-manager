# print current shell
echo $SHELL
echo $?
ps -p "$$"
readlink /proc/$$/exe
