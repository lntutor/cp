# https://www.hackerrank.com/challenges/defaultdict-tutorial
'''
DefaultDict is a container in the collections class of Python.
It is almost the same as the usual dictionary (dict) container but with one difference.
The value fields' data-type is specified upon initialization. 
A basic snippet showing the usage follows:

from collections import defaultdict
d = defaultdict(list)
d['python'].append("awesome")
d['something-else'].append("not relevant")
d['python'].append("language")
for i in d.items():
    print i
This prints:

('python', ['awesome', 'language'])
('something-else', ['not relevant'])
'''

from collections import defaultdict

d = defaultdict(list)
array = map(int, raw_input().split())
n = array[0]
m = array[1]

for i in range(1, n + 1):
    c = raw_input()
    d[c].append(i)
for i in range (0, m):
    c = raw_input()
    if len(d[c]) > 0:
        print ' '.join(map(str, d[c]))
    else:
        print -1