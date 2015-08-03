from __future__ import division
n = (int) (raw_input())
array = map(int, raw_input().split())

positive = 0
negative = 0
zero = 0

for item in array:
    if item > 0:
        positive +=1
    elif item == 0:
        zero +=1
    else:
        negative +=1
print '{0:.3f}'.format(positive/n)
print '{0:.3f}'.format(negative/n)
print '{0:.3f}'.format(zero/n)