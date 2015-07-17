# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(raw_input())
stack = [];
while n>0:
  line = raw_input()
  array = line.split()
  if array[0] == 'push':
    stack.append(int(array[1]))
    print stack[len(stack)-1]
  elif array[0] == 'pop':
    stack.pop()
    if len(stack) > 0:
        print stack[len(stack)-1]
    else: print 'EMPTY'
  elif array[0] == 'inc':
    if len(stack) > 0:
        count = 0;
        x = int (array[1])
        d = int (array[2])
        while x >0 and count < len(stack):
            stack[count] = stack[count] + d; 
            x = x-1;
            count = count + 1;
        print stack[len(stack)-1]
    else: print 'EMPTY'
  n = n - 1