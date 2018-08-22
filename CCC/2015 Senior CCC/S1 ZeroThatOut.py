import sys
input = sys.stdin.readline

k=int(input())
nums=[]
for n in range(k):
    num=int(input())
    if num == 0:#if num is zero delete last item
        del nums[-1]
    else:
        nums.append(num)#if num not zero add to list
print(sum(nums))#take sum of all items
