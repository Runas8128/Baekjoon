def logic(meetings, log=False):
    meetings.sort(key=lambda d: d[0])
    meetings.sort(key=lambda d: d[1] - d[0])
    if log: print('meetings:', meetings)
    rooms = [[meetings[0]]]
    for schedule in meetings[1:]:
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
        if not added: rooms.append([schedule])
        if log: print('checking', schedule, '\b, rooms:', rooms)
    if log: print('result:', rooms)
    return max(map(len, rooms))

def test(prompt, show_all=False):
    test_count = 0
    getting = False
    meetings = []

    for line in prompt:
        words = line.split()
        if len(words) == 0 or not words[0].isnumeric():
            continue

        value = list(map(int, words))
        if len(value) == 1:
            getting = not getting
            if getting:
                test_count += 1
                meetings = []
            else:
                correct = value[0]
                calculated = logic(meetings)
                if show_all or correct != calculated:
                    print(f"testcase #{test_count}: {'OK' if correct == calculated else 'Wrong'}")
                    print(f"correct: {correct} / calculated: {calculated}")
                    logic(meetings, not show_all)
        else:
            meetings.append(value)

with open('./question.txt', 'r', encoding='UTF-8') as f:
    test(f.readlines())
