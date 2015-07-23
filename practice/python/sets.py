# https://www.hackerrank.com/challenges/sets
'''
COMMON SET OPERATIONS - union(), intersection() and difference() 

a = {2, 4, 5, 9}
b = {2, 4, 11, 12}
a.union(b) # Values which exist in a or b
{2, 4, 5, 9, 11, 12}
a.intersection(b) # Values which exist in a and b
{2, 4}
a.difference(b) # Values which exist in a but not in b
{9, 5} 

union() and intersection() are symmetric methods i.e. to say, 

a.union(b) == b.union(a)
True
a.intersection(b) == b.intersection(a)
True
a.difference(b) == b.difference(a)
False
'''
raw_input()
listA = raw_input().split()
raw_input()
listB = raw_input().split()
setA = set(map(int, listA))
setB = set(map(int, listB))

diffA = setA.difference(setB)
diffB = setB.difference(setA)
result = sorted(list(diffA.union(diffB)))
for i in range (0, len(result)):
    print result[i]