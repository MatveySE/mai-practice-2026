import sys
 
 
input = sys.stdin.readline
t = int(input().strip())
out = []
for _ in range(t):
    a = list(map(int, input().strip().split()))
    total = sum(a)
    mx = max(a)
    ans = 2 * mx - total
    out.append(str(ans))
sys.stdout.write("\n".join(out))
