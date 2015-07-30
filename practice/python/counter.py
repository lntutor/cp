#https://www.hackerrank.com/challenges/word-order
'''
Problem Statement

You are given n words. Some words may repeat. For each word, you have to output its number of occurences. But the output order should correspond with the order of the first appearance of the word. See the sample input/output for clarification. Note that each line in the input ends with a "\n" character.

Constraints: 
1≤n≤105 
Sum of lengths of all the words do not exceed 106 
All words are composed of lowercase-latin alphabets only.

Input Format

First line contains n. 
n lines follow, ith one contains the ith word.

Output Format

Output 2 lines. 
On the first line, output the number of distinct words in the input. 
In the second line, for each distinct word, output its number of occurences in the order specified in the problem statement.
'''
from collections import Counter
n = (int)(raw_input())
list = []
while n > 0:
    item = raw_input()
    list.append(item)
    n = n - 1

cnt = Counter(list)
print len(cnt)
for word in list:
    derp = cnt.pop(word, None)
    if derp == None:
        continue
    else:
        print derp, # comma stops print from ending with newline