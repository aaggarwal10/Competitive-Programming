"""
ID: anish.51
LANG: PYTHON2
TASK: transform
"""
def rotateClockwise(grid,N):
  rows = []
  cols = []
  for i in range(len(grid)):
    rows.append(grid[i])
    cols.append([grid[n][i] for n in range(N)])
  newGrid = []
  for n in range(N):
    newGrid.append(cols[n][::-1])
  return newGrid

def rotate180(grid,N):
  return rotateClockwise(rotateClockwise(grid,N),N)

def rotate270(grid,N):
  return rotateClockwise(rotateClockwise(rotateClockwise(grid,N),N),N)

def reflectGrid(grid,N):
  newGrid = []
  for i in range(N):
    newGrid.append(grid[i][::-1])
  return newGrid
fin = open ('transform.in', 'r')
fout = open ('transform.out', 'w')


N = int(fin.readline())
grid1 = []
grid2 = []
for i in range(N):
  grid1.append(list(fin.readline().strip()))

for i in range(N):
  grid2.append(list(fin.readline().strip()))

d = {1:(rotateClockwise(grid1,N)==grid2),2:(rotate180(grid1,N)==grid2),3:(rotate270(grid1,N)==grid2),
     4:(reflectGrid(grid1,N) == grid2),6:(grid1==grid2)}
list5 = [(rotateClockwise(reflectGrid(grid1,N),N)==grid2),
     (rotate180(reflectGrid(grid1,N),N)==grid2),(rotate270(reflectGrid(grid1,N),N)==grid2)]
if True in list(d.values()):
  fout.write(str(list(d.keys())[list(d.values()).index(True)])+"\n")
elif True in list5:
  fout.write(str(5)+"\n")
else:
  fout.write(str(7)+"\n")
fout.close()
