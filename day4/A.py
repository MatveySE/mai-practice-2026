t = int(input())
 
for _ in range(t):
    a = [int(j) for j in input().split()]
    ans = 0
    for i in range(6):
        for j in range(6):
            for k in range(6):
                if i + j + k < 6:
                    ans = max(ans, (a[0] + i) * (a[1] + j) * (a[2] + k))
    print(ans)
 
 
