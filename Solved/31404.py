import sys
input = sys.stdin.readline

h, w = map(int, input().split())
r, c, d = map(int, input().split())

A = [[int(_d) for _ in range(w+1) if (_d := sys.stdin.read(1)) != '\n'] for _ in range(h)]
B = [[int(_d) for _ in range(w+1) if (_d := sys.stdin.read(1)) != '\n'] for _ in range(h)]
board = [[0 for _ in range(w)] for _ in range(h)]

count = 0
move = 0
last_dust = ()

while (0 <= c < w and 0 <= r < h):
    flag = board[r][c]
    board[r][c] += 1

    if flag == 0: d += A[r][c]
    else: d += B[r][c]
    d %= 4

    if d == 0: r -= 1
    elif d == 1: c += 1
    elif d == 2: r += 1
    else: c -= 1

    pos = (r, c, d)
    if pos == last_dust: break
    move += 1
    if flag == 0:
        last_dust = pos
        count += move
        move = 0

print(count)
