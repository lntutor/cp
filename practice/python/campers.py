# https://www.hackerrank.com/contests/countercode/challenges/campers

line1 = map(int, raw_input().split())
snipers = sorted(map(int, raw_input().split()))

n = line1[0]
k = line1[1]

player = k

if snipers[0] > 2:
    for i in xrange(1, snipers[0]-1,2):
        player +=1
#print player

if snipers[k-1] != n:
    for i in xrange(snipers[k-1]+2, n+1,2):
        player +=1
#print player

for i in range(0, k-1):
    for j in xrange(snipers[i]+2, snipers[i+1]-1,2):
        player +=1
if k == n:
    print 1
else:
    print player


