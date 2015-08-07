
# https://www.hackerrank.com/challenges/piling-up
from collections import deque

def isLessThanItemsInArray (array, value):
    if len(array) == 0:
        return True
    for item in array:
        if value > item:
            return False
    return True

def checkPillUp (array):
    if len(array) == 0:
        return True
    queue = deque(array)
    lastMax = 0
    count = 0
    tmp = lastMax
    while len(queue) > 0:
        left = queue[0]
        right = queue[len(queue) - 1]
        if left > right:
            tmp = queue.popleft()
        else:
            tmp = queue.pop()
        if count == 0:
            lastMax = tmp
        elif lastMax < tmp:
            return False
        count +=1
    return True

n = (int) (raw_input())

while n > 0:
    size = (int) (raw_input())
    array = map(int, raw_input().split())
    if checkPillUp(array):
        print 'Yes'
    else:
        print 'No'
    n -= 1
