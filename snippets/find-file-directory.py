import glob

txtfiles = []
for file in glob.glob("*.txt"):
    txtfiles.append(file)

import os
[os.path.abspath(x) for x in os.listdir())]

import os
# Getting the current work directory (cwd)
thisdir = os.getcwd()

# r=root, d=directories, f = files
for r, d, f in os.walk(thisdir):
    for file in f:
        if ".docx" in file:
            print(os.path.join(r, file))

import os
mylist = ""
with open("filelist.txt", "w", encoding="utf-8") as file:
    for eachfile in os.listdir():
        mylist += eachfile + "\n"
    file.write(mylist)

import codecs
with codecs.open("test_output", "w", "utf-8") as temp:
    temp.write("hi mom\n")
    temp.write(u"This has ♭")

lines = []
try:
    with open("a.txt") as f :
        lines = f.readlines()
except IOError:
    print 'oops'
