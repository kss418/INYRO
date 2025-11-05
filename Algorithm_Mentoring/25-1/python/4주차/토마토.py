import sys
from collections import deque
input = sys.stdin.readline

inf = 1000000000
# 매우 큰 값으로 초기화
d = [[inf] * 1010 for i in range(1010)]
a = []
q = deque()

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 다음에 볼 인덱스가 범위 밖이거나 벽인지 판단
def outrange(cy, cx):
    if cy < 0 or cx < 0 or cy >= n or cx >= m:
        return 1
    return a[cy][cx] == -1

def bfs():
    while len(q) != 0:
        cy, cx = q.popleft()
        for i in range(4):
            # 다음에 볼 인덱스
            ny = cy + dy[i]
            nx = cx + dx[i]

            # 다음에 볼 인덱스가 범위 밖이거나 벽이면 건너 뜀
            if(outrange(ny, nx)):
                continue
            # 이미 방문 했으면 건너 뜀
            if(d[ny][nx] != inf):
                continue
            # 다음에 볼 인덱스의 최단거리  배열을
            # 현재 최단거리 배열 +1로 바꿈
            d[ny][nx] = d[cy][cx] + 1
            q.append((ny, nx))

m, n = list(map(int, input().rstrip().split()))
for i in range(n):
    b = list(map(int, input().rstrip().split()))
    a.append(b)

    for j in range(len(b)):
        if a[i][j] != 1:
            continue
        # 현재 인덱스가 익은 토마토면
        # 거리 배열을 0으로 바꾸고 큐에 삽입
        d[i][j] = 0
        q.append((i, j))

bfs()

result = 0
for i in range(n):
    for j in range(m):
        if a[i][j] == -1:
            continue
        result = max(result, d[i][j])

# 모든 토마토가 익을 수 없으면 -1
print(-1 if result == inf else result)

