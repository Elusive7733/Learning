import urllib.request, urllib.parse, urllib.error

file = open('mbox.txt', "wt")
fhand = urllib.request.urlopen('https://www.py4e.com/code3/mbox.txt')
for line in fhand:
    print(line.decode())
file.close()