import sys

for line in sys.stdin:
    k = int(line)
    
    if k == 0:
        break
      
    if k % 17 == 0:
        print(1)
    else:
        print(0)
