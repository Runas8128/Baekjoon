import sys
input = sys.stdin.readline

n, m = map(int, input().split())
friends = [list(map(int, input().split())) for _ in range(m)]

memo = {}

def path_length(src: int, dst: int) -> int:
    if src == dst: return 0
    if (src, dst) in memo.keys(): return memo[(src, dst)]
    if (dst, src) in memo.keys(): return memo[(dst, src)]
    _friends = friends[:]
    depth = 1
    search = [src, -1]
    while len(search) > 0:
        tar = search.pop(0)
        if tar == -1:
            depth += 1
            continue
        for a, b in _friends:
            if a == tar:
                if b == dst: memo[(src, dst)] = depth; return depth
                else: search.append(b)
                _friends.remove(a, b)
            elif b == tar:
                if a == dst: memo[(src, dst)] = depth; return depth
                else: search.append(a)
                _friends.remove(a, b)
        search.append(-1)
    return -1

def Kevin_Bacon(k: int) -> int:
    rst = 0
    for i in range(1, n+1): rst += path_length(k, i)
    return rst

data = [Kevin_Bacon(k) for k in range(1, n+1)]
print(data.index(min(data)) + 1)
