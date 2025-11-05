import sys
from collections import deque
input = sys.stdin.readline

MAX = 50101
INF = 10**12

n = m = 0
ind = [0] * MAX
adj = [[] for _ in range(MAX)]
q = deque()

n, m = map(int, input().split())

for _ in range(m):
    s, e = map(int, input().split())
    adj[s].append(e)
    ind[e] += 1

for i in range(1, n + 1):
    # 들어오는 간선이 없으면 큐에 삽입
    if ind[i] == 0:
         q.append(i)

while q:
    cur = q.popleft()
    # 현재 큐의 값 출력
    print(cur, end=' ')
    for nxt in adj[cur]:
        ind[nxt] -= 1
        # 다음 정점이 들어오는 간선이 없으면 큐에 삽입
        if ind[nxt] == 0:
            q.append(nxt)

