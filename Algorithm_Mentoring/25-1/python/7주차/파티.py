import sys
import heapq
input = sys.stdin.readline

INF = 10**12
n, m, x = map(int, input().split())

adj = [[[] for _ in range(2)] for _ in range(n+1)]
for _ in range(m):
    s, e, c = map(int, input().split())
    # 정방향 간선
    adj[s][0].append((e, c))
    # 역방향 간선
    adj[e][1].append((s, c))

d = [[INF, INF] for _ in range(n+1)]
for i in range(2):
    pq = []
    heapq.heappush(pq, (0, x))
    while pq:
        cd, cur = heapq.heappop(pq)
        if d[cur][i] <= cd:
            continue
        d[cur][i] = cd
        for nxt, co in adj[cur][i]:
            nd = cd + co
            if d[nxt][i] > nd:
                heapq.heappush(pq, (nd, nxt))

result = 0
for i in range(1, n+1):
    # 역방향 간선 + 정방향 간선의 최댓값
    result = max(result, d[i][0] + d[i][1])

print(result)

