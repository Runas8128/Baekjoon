import sys
input = sys.stdin.readline

n = int(input())
s = input().replace(' ', '')
if len(set(s)) <= 2: print(n) ; exit(0)

ml = 0

kind = {'1':0,'2':0,'3':0,'4':0,'5':0,'6':0,'7':0,'8':0,'9':0}
end = 0
for begin in range(n):
    while end < n:
        kind[s[end]] += 1
        if sum([1 for k, v in kind.items() if v > 0]) < 3:
            end += 1
        else:
            break
    if (end - begin) > ml: ml = end - begin
    kind[s[begin]] -= 1
    end += 1

print(ml)
