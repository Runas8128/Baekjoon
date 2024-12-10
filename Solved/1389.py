import sys
input = sys.stdin.readline

n, m = map(int, input().split())
friends = [list(map(int, input().split())) for _ in range(m)]

# maximum distance is 99
dmap = [[
    0 if i == j
    else (1 if [i, j] in friends or [j, i] in friends
          else 100)
    for j in range(1, n+1)] for i in range(1, n+1)
]

for i in range(n):
    dmap = [[min(dmap[a][b], dmap[a][i] + dmap[i][b]) for b in range(n)] for a in range(n)]

dists = [sum(d) for d in dmap]
print(dists.index(min(dists))+1)
