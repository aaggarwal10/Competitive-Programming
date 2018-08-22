string1 = list(input())
string2 = list(input())
for i in string1:#loop through string
  if i in string2:
    string2.remove(i)#if the character that was in string1 is in string2, then remove it from string 2
if list(set(string2)) == ["*"] or string2 == []:#is the list with no duplicates consists of an "*" or is empty it is wild
  print("A")
else:#otherwise it isn't
  print("N")
