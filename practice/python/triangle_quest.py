#1
#22
#333
#4444
#55555
#https://en.wikipedia.org/wiki/Repunit
for i in range(1,input()): #More than 2 lines will result in 0 score. Do not leave a blank line also
    print i*(10**i-1)/(10-1)