import sys
filename = sys.argv[1]
s = """
#ifndef INDEX_H
#define INDEX_H
int five();
#endif """

a = open(filename, "w+")
a.write(str(s))
a.close()

