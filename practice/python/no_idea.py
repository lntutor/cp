#https://www.hackerrank.com/challenges/no-idea
'''
Problem Statement

There is an array of n integers, and 2 disjoint sets of m integers each A and B. 
You like all integers in A and dislike all integers in B.
Your initial happiness is 0 and for each integer in the array, i,
if i∈A, you add 1 to your happiness, if i∈B, you add −1 to your happiness, else your happiness does not change. Output your final happiness at the end.
Note that since A and B are sets, they have no repeated elements. But, the array might contain duplicate elements.
'''
from collections import defaultdict

dictA = defaultdict(list)
dictB = defaultdict(list)

size = map(int, raw_input().split())
n = size[0]
m = size[1]

happy = 0
unhappy = 0
array = raw_input().split()
arrayA = raw_input().split()
arrayB = raw_input().split()

for i in range (0, m):
	dictA[arrayA[i]] = i + 1
for i in range (0, m):
	dictB[arrayB[i]] = i + 1

for i in range(0,n):
    if array[i] in dictA:
		happy = happy + 1
    elif array[i] in dictB:
        happy = happy - 1
print happy