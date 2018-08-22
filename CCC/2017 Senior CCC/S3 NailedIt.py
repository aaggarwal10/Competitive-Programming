import sys
input = sys.stdin.readline

input() # we don't need that value >_<

items = [0]*2001
for i in input().split():
  items[int(i)] += 1

sums  = [0]*4001
for i, v in enumerate(items):
  if v: # Since length 0 pieces of wood cannot be used, this is put to avoid pointless calculation. 
    for j, x in enumerate(items[i:]):
      if i == j+i: # j+i because of how enumerate works. Of course I don't need to use enumerate at all, who could pass up meaningless pain and suffering :D /jk, it was put so I could feel better about reading the editorial.
        sums[i+j+i] += v/2 # Because 2 pieces of wood are needed and since the same value is used twice the plank is added by half to avoid duplication. 
      else:
        print(x)
        sums[i+j+i] += min(v,x) # Adds the lower of the 2 values because 2 pieces of wood are required. This makes sure that a plank can't have a 0 length piece of wood (and that there's not always a perfect 1/1 ratio of pieces of wood to add).
print(sums)
maxLen = max(sums) 
maxNum = sums.count(maxLen)

print ("{0} {1}".format(maxLen, maxNum))
