import sys


input = sys.stdin.readline
t = int(input())
out = []
for _ in range(t):
    n, c, d = map(int, input().split())
    b = list(map(int, input().split()))
    b.sort()
    a = b[0] 

    expected = []
    for i in range(n):
        row_start = a + i * c
        for j in range(n):
            expected.append(row_start + j * d)
    expected.sort()

    out.append("YES" if b == expected else "NO")

sys.stdout.write("\n".join(out))

