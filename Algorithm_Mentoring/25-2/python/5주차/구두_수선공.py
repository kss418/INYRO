import sys
input = sys.stdin.readline

n = int(input())
a = []
for i in range(1, n + 1):
    t, s = map(int, input().split())
    a.append((t / s, i))

a.sort()

for _, idx in a:
    print(idx, end=" ")
