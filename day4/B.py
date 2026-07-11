t = int(input())
 
for _ in range(t):
    n, k = map(int, input().split())
    a = [int(i) for i in input().split()]
    print(2 * (n - max(a)) - k + 1)
 
 
