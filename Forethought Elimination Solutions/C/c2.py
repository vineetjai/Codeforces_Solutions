import sys
t = int(raw_input())
for __ in xrange(t):
    n = int(raw_input())
    ans = 0
    for i in xrange(7):
        a = []
        b = []
        for j in xrange(n):
            if (j>>i)&1:
                a.append(j+1)
            else:
                b.append(j+1)
        if len(a) and len(b):
            print len(a), len(b), " ".join(map(str, a)), " ".join(map(str, b))
            sys.stdout.flush()
            ans = max(ans, int(raw_input()))
    print -1, ans
    sys.stdout.flush()
