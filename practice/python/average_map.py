'''
Sample Input 
3
Krishna 67 68 69
Arjun 70 98 63
Malika 52 56 60
Malika
Sample Output

56.00
'''

n = (int) (raw_input())
n = n + 1
my_map = {}
while n > 0:
    line = raw_input()
    array = line.split()
    if len(array) > 1:
        #print array
        sum = 0
        for i in range(1, len(array)):
            sum = sum + (float) (array[i])
        average = (float)(sum/(len(array)-1))
        key = array[0]
        my_map[key] = average
    else:
        print '{0:.2f}'.format(my_map[line])
    n = n-1