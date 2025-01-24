import sys
input = sys.stdin.readline

n = int(input())
meetings = [list(map(int, input().split())) for _ in range(n)]

meetings.sort(key=lambda d: d[0])
meetings.sort(key=lambda d: d[1] - d[0])
rooms = [[meetings.pop(0)]]

for schedule in meetings:
    added = False
    for room in rooms:
        if schedule[1] <= room[0][0]:
            room.insert(0, schedule)
            added = True
            break
        if room[-1][1] <= schedule[0]:
            room.append(schedule)
            added = True
            break
        for idx in range(len(room)-1):
            if room[idx][1] <= schedule[0] and \
                schedule[1] <= room[idx+1][0]:
                room.insert(idx+1, schedule)
                added = True
                break
        if added: break
    if not added: rooms.append([schedule])

print(max(map(len, rooms)))
