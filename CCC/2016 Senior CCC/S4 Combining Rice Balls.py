import sys

def make_canDo(n, prefs):
  mem = dict()
  def canDo(i, j):
    if j-i <= 1: return True
    if (i, j) in mem: return mem[(i, j)]

    ans = False
    ii, jj = i+1, j-1
    while (not ans) and (ii <= jj):
      if (prefs[ii] - prefs[i]) == (prefs[j] - prefs[jj]):
        ans = canDo(i, ii) and canDo(ii, jj) and canDo(jj, j)
      if (prefs[ii] - prefs[i]) < (prefs[j] - prefs[jj]):
        ii += 1
      else:
        jj -= 1

    mem[(i, j)] = ans
    pprint(mem)
    return ans
  return canDo

n = int(input())
balls = list(map(int, input().split()))

prefs = [0]
for b in balls:
  prefs.append(prefs[-1] + b)

best = max(balls)
canDo = make_canDo(n, prefs)
for i in range(n):
  for j in range(i+2, n+1):
    if (prefs[j] - prefs[i] > best) and canDo(i, j):
      best = prefs[j] - prefs[i]

print(best)

