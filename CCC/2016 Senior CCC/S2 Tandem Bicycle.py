query = int(input())#get what question is being asked
players = int(input())
#sort both inputs
cyclists1 = sorted(list(map(int,input().split())))
cyclists2 = sorted(list(map(int,input().split())))

cyc = 0 #count of total
if query==2:#if query is 2 which is asking for max u want the mins of on list to be paired up with max of other list so u flip one list, if it was query 1 then u want it to be minimum so pair min with min and max with max
  cyclists2 = cyclists2[::-1]
for i in range(players):#loop through players and add the max of the two
  cyc+=max(cyclists1[i],cyclists2[i])
print(cyc)
