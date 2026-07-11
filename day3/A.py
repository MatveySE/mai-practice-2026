mod = 10 ** 9 + 7
 
n, k, m = map(int, input().split())
 
a = set(map(int, input().split())) if m else set()
 
dp = [0] * (n + 1)
dp[0] = 1
 
cache = 1
 
for i in range(1, n + 1):
    if i not in a:
        dp[i] = cache % mod
 
    cache = (cache + dp[i]) % mod
 
    if i - k >= 0:
        cache = (cache - dp[i - k]) % mod
 
print(dp[n])
