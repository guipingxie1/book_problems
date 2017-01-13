import sys

for line in sys.stdin:
    arr = [int(n) for n in line.split()]
    if (len(arr) == 0):
        break
        
    n = arr[0]
    a = arr[1]
    s = 0
    
    for i in range(1, n + 1):
        s += i * a ** i
        
    print(s)
