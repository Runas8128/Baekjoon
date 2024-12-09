import sys
input = sys.stdin.readline

n, m = map(int, input().split())
points = list(range(1, n+1))
lines = [list(map(int, input().split())) for _ in range(m)]
count = 0

while len(points) > 0:
    visit = [points.pop(0)]
    while len(visit) > 0:
        pos = visit.pop(0)
        for (u, v) in lines:
            if u == pos and v in points:
                points.remove(v)
                visit.append(v)
            elif v == pos and u in points:
                points.remove(u)
                visit.append(u)
        lines = list(filter(lambda d: pos != d[0] and pos != d[1], lines))
    count += 1
print(count)
