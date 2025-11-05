import sys
from collections import deque
input = sys.stdin.readline
v = [0] * 10
a = [[] for _ in range(10)]

def add(s, e):
    # 양방향 간선 추가
    a[s].append(e)
    a[e].append(s)

def bfs(st):
    q = deque()
    # 큐에 시작점 추가 및 방문 처리
    q.append(st)
    v[st] = 1

    while len(q) != 0:
        cur = q.popleft()
        print(cur)
        for nxt in a[cur]:
            # 방문한 정점이면 넘어 감
            if v[nxt] == 1:
                continue
            # 큐에 다음 정점 삽입 및 방문 처리
            v[nxt] = 1
            q.append(nxt)

add(1, 2)
add(2, 4)
add(2, 5)
add(1, 3)
add(3, 6)
add(6, 7)

bfs(1)
