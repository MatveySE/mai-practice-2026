import sys
 
 
input = sys.stdin.readline
t = int(input().strip())
out = []
for _ in range(t):
    x = int(input().strip())
    y = x + 1 if x < 67 else 67
    out.append(str(y))
sys.stdout.write("\n".join(out))
