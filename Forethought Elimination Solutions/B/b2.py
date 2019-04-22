t = raw_input()

c0 = t.count('a')
c1 = len(t)-c0

if c1 % 2 == 1:
    print ":("
else:
    tna = t.replace('a', '')
    tx1 = tna[:c1/2]
    tx2 = tna[c1/2:]
    if c1 == 0:
        print t
    elif (tx2 == t[-(c1/2):] and tx1 == tx2):
        print t[:-(c1/2)]
    else:
        print ":("

