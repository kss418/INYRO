import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
m = int(input())

ind = [0] * (n + 1)
dp = [[0] * (n + 1) for _ in range(n + 1)]
basic = []
q = deque()
adj = [[] for _ in range(n + 1)]
    
for _ in range(m):
    e, s, c = map(int, input().split())
    adj[s].append((e, c))
    ind[e] += 1

for i in range(1, n + 1):
    if ind[i]:
        continue
    # ind[i] == 0 이면
    # 큐에 넣고 기본 부품으로 지정
    q.append(i)
    basic.append(i)
    # 기본 부품을 만드는데는 자기 자신 1개가 필요함
    dp[i][i] = 1


while q:
    cur = q.popleft()
    for nxt, co in adj[cur]:
        # dp[nxt]를 만드는데 드는 부품은 dp[cur] * co 만큼 추가로 들음
        # 각 부품 1 ~ N 까지 반복해야 함
        for i in range(1, n + 1):
            dp[nxt][i] += dp[cur][i] * co
        ind[nxt] -= 1
        if ind[nxt] == 0:
            q.append(nxt)

# 기본 부품에 대해서만 개수 출력
for i in basic:
    print(i, dp[n][i])


