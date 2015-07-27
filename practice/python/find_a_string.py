parent = raw_input()
child = raw_input()
count = 0
for i in range (0, len(parent) - len(child) + 1):
    if parent[i: i + len(child)] == child:
        count = count + 1
print count