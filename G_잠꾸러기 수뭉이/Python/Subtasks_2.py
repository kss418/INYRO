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
    # 이동 시간이 같으면 True 아니면 False 반환
    return ret <= t0 + cur

def run():
    global N, M, t0, dij
    N, M = map(int, input().split())
    dij = _dij(N)
    # 간선 입력
    for _ in range(M):
        s, e, c, l = map(int, input().split())
        dij.add(s, e, c, l)

    # 출발 시간이 0일 때의 최단 거리
    t0 = dij.ret(1, N, 0)

    # 출발 시간이 0일 때 도달 불가능하면 -1
    if t0 >= INF:
        print(-1)
    else:
        print(t0, end=' ')
        for i in range(21):
            # 출발 시간이 i일 때 이동 시간이 같으면 건너뜀
            if decision(i):
                continue
            # 가장 처음으로 이동 시간이 달라진 출발 시간 출력
            print(i - 1)
            return
        # for문을 다 돌아도 이동 시간이 같으면 20
        print(20)

t = int(input())
for _ in range(t):
    run()

