import sys
import heapq
input = sys.stdin.readline

MAX = 40101
INF = 10**12

n, m = map(int, input().split())
ind = [0] * MAX
adj = [[] for _ in range(MAX)]
pq = []

for _ in range(m):
    s, e = map(int, input().split())
    adj[s].append(e)
    ind[e] += 1

# 우선순위 큐 사용
for i in range(1, n + 1):
    if ind[i] == 0:
        heapq.heappush(pq, i)

while pq:
    cur = heapq.heappop(pq)
    print(cur, end=' ')
    for nxt in adj[cur]:
        ind[nxt] -= 1
        if ind[nxt] == 0:
            heapq.heappush(pq, nxt)
ㄴ