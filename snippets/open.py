lines = []
try:
    with open('file.txt') as f:
        lines = f.readlines()
except IOError:
    print "oops"
