t = raw_input()
c = [t.count(chr(ord('a')+i)) for i in xrange(26)]
ww = [0 for __ in xrange(26)]
for j in xrange(len(t)):
    ww[ord(t[j]) - ord('a')] += 1
    if ww[0] != c[0]: continue

    for k in xrange(1,26):
        if ww[k] * 2 != c[k]:
            break
    else:
        if t[:j+1].replace('a', '') == t[j+1:]:
            print t[:j+1]
            break
else:
    print ":("
