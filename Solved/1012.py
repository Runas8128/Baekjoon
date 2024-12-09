import sys

for _ in range(int(sys.stdin.readline())):
    m, n, k = map(int, sys.stdin.readline().split())
    pos = [list(map(int, sys.stdin.readline().split())) for _ in range(k)]
    count = 0
    while len(pos) > 0:
        section = [pos.pop(0)]
        while len(section) > 0:
            now = section.pop(0)
            target = [
                [now[0] - 1, now[1]],
                [now[0] + 1, now[1]],
                [now[0], now[1] - 1],
                [now[0], now[1] + 1],
            ]
            for p in target:
                if p in pos:
                    pos.remove(p)
                    section.append(p)
        count += 1

    print(count)
