from collections import deque
import sys
input = sys.stdin.readline

MAX = 1010
INF = 10**12

n = m = k = 0
ind = [0] * MAX
a = [0] * MAX
dp = [0] * MAX
adj = [[] for _ in range(MAX)]
q = deque()

def run():
    global n, m, k, ind, a, dp, adj, q
    q.clear()
    n, m = map(int, input().split())

    # 값 입력 및 초기화
    for i in range(1, n+1):
        a[i] = int(input())
        dp[i] = ind[i] = 0
        adj[i].clear()

    # 간선 입력
    for _ in range(m):
        s, e = map(int, input().split())
        adj[s].append(e)
        ind[e] += 1

    k = int(input())

    for i in range(1, n+1):
        if ind[i] == 0:
            q.append(i)

    while q:
        cur = q.popleft()
        # 현재 DP값에 현재 건물 짓는 데 걸리는 시간 추가
        dp[cur] += a[cur]
        for nxt in adj[cur]:
            # 다음 DP 값은 이전의 건물을 짓는 데 드는
            # 시간 중 최댓값으로 갱신
            dp[nxt] = max(dp[nxt], dp[cur])
            ind[nxt] -= 1
            if ind[nxt] == 0:
                q.append(nxt)
                
    print(dp[k])

t = int(input())
for _ in range(t):
    run()
