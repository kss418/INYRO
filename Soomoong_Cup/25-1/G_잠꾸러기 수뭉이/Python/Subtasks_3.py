import sys
import heapq
input = sys.stdin.readline

INF = 10**12

# 다익스트라
class _dij:
    class node:
        def __init__(self, nxt, c, l):
            self.nxt = nxt
            self.c = c
            self.l = l

    def __init__(self, n=0):
        self.n = n
        self.adj = [[] for _ in range(n + 1)]
        self.dist = []
        self.pq = []

    # 간선 추가
    def add(self, s, e, c, l):
        self.adj[s].append(self.node(e, c, l))
        self.adj[e].append(self.node(s, c, l))
    # s -> e 최단거리 반환
    def ret(self, s, e, t):
        self.dist = [INF] * (self.n + 1)
        self.pq.clear()
        heapq.heappush(self.pq, (t, s))

        while self.pq:
            cd, cur = heapq.heappop(self.pq)
            if self.dist[cur] <= cd:
                continue
            self.dist[cur] = cd

            for nxt_node in self.adj[cur]:
                # 현재 최단거리가 막차 시간 이상이면 건너 뜀
                nxt, co, ban = nxt_node.nxt, nxt_node.c, nxt_node.l
                if cd >= ban:
                    continue
                if self.dist[nxt] <= cd + co:
                    continue
                heapq.heappush(self.pq, (cd + co, nxt))

        return self.dist[e]

dij = _dij()
t0 = 0
N = 0
M = 0

def decision(cur):
    # 출발 시간이 cur일 때 정점 N까지의 최단 거리
    ret = dij.ret(1, N, cur)
    # 이동 시간이 같으면 1 반환
    return ret <= t0 + cur

# 매개 변수 탐색
def maximization():
    lo, hi = 0, 101010
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if decision(mid):
            # mid 일 때 이동 시간이 같으면 lo -> mid로 변경
            lo = mid
        else:
            #  mid 일 때 이동 시간이 다르면 hi -> mid - 1로 변경
            hi = mid - 1
    return lo

def run():
    global N, M, t0, dij
    N, M = map(int, input().split())
    dij = _dij(N)

    for _ in range(M):
        # 간선 입력
        s, e, c, l = map(int, input().split())
        dij.add(s, e, c, l)

    # 출발 시간이 0일 때의 최단 거리
    t0 = dij.ret(1, N, 0)

    # 출발 시간이 0일 때 정점 N에 도착하지 못하면 -1
    if t0 >= INF:
        print(-1)
    else:
        # 매개변수 탐색으로 가장 처음으로 
        # 이동시간이 달라진 출발 시간을 구함
        print(t0, maximization())


t = int(input())
for _ in range(t):
    run()
