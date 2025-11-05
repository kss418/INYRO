import sys
import heapq
input = sys.stdin.readline

INF = 10**12

n = int(input().rstrip())
m = int(input().rstrip())
adj = [[] for _ in range(n + 1)]
for _ in range(m):
    s, e, c = map(int, input().split())
    adj[s].append((e, c))

s, e = map(int, input().split())

# 거리 배열 큰 값으로 초기화
dist = [INF] * (n + 1)

pq = []
# 시작 정점을 방문 가능한 정점으로 처리
heapq.heappush(pq, (0, s))

while pq:
    # 방문 가능한 정점 중 최단 거리인 정점 방문
    cd, cur = heapq.heappop(pq)
    # 이미 최단거리이면 건너 뜀
    if dist[cur] <= cd:
        continue
    
    # 거리 갱신
    dist[cur] = cd
    for nxt, co in adj[cur]:
        nd = cd + co
        # 현재 거리가 최단 거리이면
        if dist[nxt] > nd:
            # 방문 가능한 정점에 포함
            heapq.heappush(pq, (nd, nxt))

print(dist[e])

