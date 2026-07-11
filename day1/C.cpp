import sys
 
input = sys.stdin.readline
 
t = int(input().strip())
for _ in range(t):
    n = int(input().strip())
    perm = []
    for k in range(n):
        small = k + 1
        med = n + 1 + 2 * k
        large = n + 2 + 2 * k
        perm.extend([small, med, large])
    print(' '.join(map(str, perm)))
