"""
ID: anish.51
LANG: PYTHON2
TASK: namenum
"""
d = {2:["A","B","C"],3:["D","E","F"],
     4:["G","H","I"],5:["J","K","L"],
     6:["M","N","O"],7:["P","R","S"],
     8:["T","U","V"],9:["W","X","Y"]}
def addName(count,curstring):
  global numoflet,name,posNames
  count+=1
  if count==numoflet:
    posNames.append(curstring)
  else:
    for i in d[name[count]]:
      addName(count,curstring+i)

fin = open ("namenum.in", 'r')
fout = open ("namenum.out", 'w')

name = list(map(int,list(fin.readline().strip())))
numoflet=len(name)


dIn = open("dict.txt",'r')
validNames= [line.rstrip('\n') for line in dIn]
validNames = set(validNames)

posNames = []
for i in d[name[0]]:
  addName(0,i)

printed=False
for name in posNames:
  nam = "".join(name)
  if nam in validNames:
    fout.write(nam +"\n")
    printed = True
if not printed:
  fout.write("NONE\n")

fout.close()
