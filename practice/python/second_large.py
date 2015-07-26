raw_input()
array = map(int, raw_input().split())
array = sorted(array)
max = array[len(array)-1]
n = len(array) - 1
while n >= 0:
    if max > array[n]:
        max = array[n]
        print max
        break
    n = n - 1