input()#dont care about this input as you really dont need it >_<
tidesList = list(map(int,input().split()))#get a list of the input
tidesList = sorted(tidesList)#use cool function
if len(tidesList)%2==0:#if length of list is divisible by two split it in half and half for high and low
  lowTides = tidesList[:len(tidesList)//2][::-1]
  highTides = tidesList[len(tidesList)//2:]
else:#if length of list is odd add one more element to lowTides then high tides as lowtides and high tides alternate so there will be one more low tide(e.g L H L H L)
  lowTides = tidesList[:len(tidesList)//2+1][::-1]
  highTides = tidesList[len(tidesList)//2+1:]
properList=[]#make list to output
lengthLowTides = len(highTides)
for i in range(len(lowTides)):#loop through to append and be careful that the length of lowTides might be larger than highTides
  properList.append(lowTides[i])
  if (i<lengthLowTides):
    properList.append(highTides[i])

print(*properList)#print list elements joined with a space
