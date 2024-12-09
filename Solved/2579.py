import sys

n = int(sys.stdin.readline())
stairs = [0]
for _ in range(n): stairs.append(int(sys.stdin.readline()))

if n == 1:
    print(stairs[1])
elif n == 2:
    print(stairs[1] + stairs[2])
else:
    data = [0, stairs[1], stairs[1] + stairs[2]]

    for i in range(3, n+1):
        data.append(stairs[i] + max(stairs[i-1] + data[i-3], data[i-2]))

    print(data[n])
