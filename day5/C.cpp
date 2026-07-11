t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    profit = []
    for _ in range(n):
        profit.append([0] + list(map(int, input().split())))

    dp = [0] * (m + 1)

    for i in range(n):
        new = [0] * (m + 1)

        for money in range(m + 1):
            best = 0
            for invest in range(money + 1):
                best = max(best, dp[money - invest] + profit[i][invest])
            new[money] = best

        dp = new

    print(dp[m])
