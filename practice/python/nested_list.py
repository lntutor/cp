n = (int) (raw_input())
array = []
min_mark = -1
mark_array = []
count = n

while count > 0:
    name = raw_input()
    mark = (float) (raw_input())
    mark_array.append(mark)
    if count == n:
        min_mark = mark
    elif min_mark > mark:
        min_mark = mark
    array.append([name, mark])
    count = count -1

# find second lowest
mark_array = sorted(mark_array)
second_lowest = -1
for i in range (0, len(mark_array)):
    if i == 0:
        second_lowest = mark_array[i]
    elif second_lowest != mark_array[i]:
        second_lowest = mark_array[i]
        break
        
array = sorted(array)

for i in range(0, n):
    if array[i][1] == second_lowest:
        print array[i][0]