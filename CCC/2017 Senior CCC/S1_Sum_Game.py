N = int(input())
team1 = list(map(int,input().split()))
team2 = list(map(int,input().split()))
for i in range(1,N):#since both lists have same length, loop through both and create a prefix sum array
  team1[i]+=team1[i-1]
  team2[i]+=team2[i-1]
  
while N:#if any of the two lists are equal at a given index print that day
  if team1[N-1] == team2[N-1]:
    print(N)
    break
  N-=1
if N==0:#if N reaches that means it will never be equal on a given day; thus, print 0 = N.
  print(N)
