import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

MAX = 7010
a = [[False] * MAX for _ in range(MAX)]

def dnc(cur, cy, cx):
    # Base Case
    if cur == 1:
        a[cy][cx] = True
        return

    nxt = cur // 3
    for i in range(3):
        for j in range(3):
            # 가운데면 건너 뜀
            if i == 1 and j == 1:
                continue

            # 분할
            dnc(nxt, cy + i * nxt, cx + j * nxt)

n = int(input())
dnc(n, 0, 0)

for i in range(n):
    for j in range(n):
        print('*' if a[i][j] else ' ', end = '')
    print()

