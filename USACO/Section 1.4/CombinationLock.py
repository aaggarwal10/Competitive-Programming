"""
ID: anish.51
LANG: PYTHON2
TASK: combo
"""
fin = open ("combo.in", 'r')
fout = open ("combo.out", 'w')

N = int(fin.readline().strip())
johnCombination = list(map(int,fin.readline().strip().split()))
masterCombination = list(map(int,fin.readline().strip().split()))
combinations = set()

def addCombination(combinationList,originalC):
  if len(combinationList)==3:
    combinations.add(tuple(combinationList))
  else:
    index = len(combinationList)
    for i in range(-2,3,1):
      newCombinationList = combinationList[:]
      newCombinationList.append(originalC[index])
      newCombinationList[-1]+=i
      newCombinationList[-1]%=N
      newCombinationList[-1]+=1
      addCombination(newCombinationList,originalC)
addCombination([],johnCombination)
addCombination([],masterCombination)
fout.write(str(len(combinations))+"\n")
fout.close()
    
