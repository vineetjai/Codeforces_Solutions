import sys
t = int(raw_input())

def ask(a,b):
    print len(a), len(b), " ".join(map(str,a)), " ".join(map(str,b))
    sys.stdout.flush()
    r = int(raw_input())
    if r == -1:
        sys.exit(0)
    return r

for __ in xrange(t):
    n = int(raw_input())
    s = [i for i in xrange(2,n+1)]
    bdist = ask([1], s)
    while len(s) > 1:
        k = len(s)/2
        s = s[:k] if ask([1], s[:k]) == bdist else s[k:]
    x = ask([s[0]], [i for i in xrange(1,n+1) if i != s[0]])
    print -1, x
    sys.stdout.flush()
