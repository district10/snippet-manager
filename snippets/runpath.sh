$ export LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH

# unset env var first
$ unset LD_LIBRARY_PATH

# rpath
$ gcc -L/home/username/foo -Wl,-rpath=/home/username/foo -Wall -o test main.c -lfoo

$ ldconfig -p | grep foo
