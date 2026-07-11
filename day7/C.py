import sys



input = sys.stdin.readline
t = int(input())
out = []
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    l, r = 0, n - 1
    total = 0
    ans = 0

    if n == 1:
        out.append('1' if k >= a[0] else '0')
        continue

    hp_l = a[l]
    hp_r = a[r]

    while l <= r and total < k:
        if l == r:
            remaining = k - total
            if remaining >= hp_l:
                ans += 1
            break

        max_cycles = min(hp_l, hp_r, (k - total) // 2)

        if max_cycles > 0:
            hp_l -= max_cycles
            hp_r -= max_cycles
            total += 2 * max_cycles

            if hp_l == 0:
                ans += 1
                l += 1
                if l <= r:
                    if l == r:
                        hp_l = hp_r
                    else:
                        hp_l = a[l]

            if hp_r == 0:
                ans += 1
                r -= 1
                if l <= r:
                    if l == r:
                        hp_r = hp_l
                    else:
                        hp_r = a[r]
        else:
            side = 0 if total % 2 == 0 else 1 
            if side == 0:
                hp_l -= 1
                total += 1
                if hp_l == 0:
                    ans += 1
                    l += 1
                    if l <= r:
                        if l == r:
                            hp_l = hp_r
                        else:
                            hp_l = a[l]
            else:
                hp_r -= 1
                total += 1
                if hp_r == 0:
                    ans += 1
                    r -= 1
                    if l <= r:
                        if l == r:
                            hp_r = hp_l
                        else:
                            hp_r = a[r]

    out.append(str(ans))

sys.stdout.write("\n".join(out))

