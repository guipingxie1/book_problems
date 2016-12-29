import sys

for line in sys.stdin:
    arr = [int(n) for n in line.split()]
    if (len(arr) == 0):
        break
        
    ma = arr[0]
    mi = arr[0]
    best = arr[0]
    
    for i in range(1, len(arr) - 1):
        co = ma;
        ma = max(arr[i], ma * arr[i], mi * arr[i])
        mi = min(arr[i], co * arr[i], mi * arr[i])
        best = max(best, ma)
        
    print(best)
