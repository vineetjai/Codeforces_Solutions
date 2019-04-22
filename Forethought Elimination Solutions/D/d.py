m,a,b = map(int, raw_input().split())

seen = set()
cmod = 0
cneed = 0
cmin = 0

def sumrange(f,t):
    if t<f: return 0
    return (f+t)*(t-f+1)/2

ans = 0
while cmod not in seen:
    seen.add(cmod)

    if cneed <= m:
        x1 = (cneed-cmod)/a + 1
        x2 = (m-cmod)/a + 1
        if x1 == x2:
            ans += (m-cneed+1)*x1
        else:
            a1 = ((cmod-cneed)%a)
            ans += a1 * x1
            if a1 != 0: x1 += 1

            a2 = (1 + ((m-cmod)%a))
            ans += a2 * x2
            if a2 != 0: x2 -= 1
            ans += a * sumrange(x1,x2)

    needa = max(0, (b-cmin+a-1)/a)
    cmin += needa*a
    cneed = max(cmin, cneed)
    cmin -= b
    cmod = cmin%a

print ans
