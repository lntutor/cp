# https://www.hackerrank.com/challenges/python-lists

n = (int) (raw_input())
result = []
while n > 0:
    array = raw_input().split()
    if array[0] == 'insert':
        result.insert((int)(array[1]), (int)(array[2]))
    elif array[0] == 'print':
        print result
    elif array[0] == 'remove':
        result.remove((int) (array[1]))
    elif array[0] == 'append':
        result.append((int) (array[1]))
    elif array[0] == 'sort':
        result.sort()
    elif array[0] == 'reverse':
        result.reverse()
    elif array[0] == 'pop':
        result.pop()
    n = n -1