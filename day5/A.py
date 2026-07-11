n = int(input())

a = []
for i in range(n):
    a.append(list(map(int, input().split())))

dp = [[0] * (i + 1) for i in range(n)]

dp[0][0] = a[0][0]

for i in range(1, n):
    for j in range(i + 1):
        left = -1
        right = -1

        if j > 0:
            left = dp[i - 1][j - 1]
        if j < i:
            right = dp[i - 1][j]

        dp[i][j] = a[i][j] + max(left, right)

print(max(dp[-1]))
