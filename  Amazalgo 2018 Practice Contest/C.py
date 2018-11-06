def consecutive_groups(iterable):
    s = tuple(iterable)
    for size in range(1, len(s)+1):
        for index in range(len(s)+1-size):
            yield iterable[index:index+size]
s=""

list(consecutive_groups('abcd'))