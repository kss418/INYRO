import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

INF = 10**12
def solve(cur):
    if cur < 0:
        return INF
    
    if dp[cur] != -1:
        return dp[cur]
    
    # Base case
    if cur == 0:
        dp[cur] = 0
        return 0

    # min값을 구하기 위해서 큰 수로 초기화
    dp[cur] = INF

    # 각 동전을 1개 씩 사용해서 cur을 만들 때 최솟값
    for i in range(1, n+1):
        dp[cur] = min(dp[cur], solve(cur - a[i]) + 1)

    return dp[cur]

n, m = map(int, input().split())
a = [0] * (n+1)
for i in range(1, n+1):
    a[i] = int(input())

dp = [-1] * (m+1)

result = solve(m)
# 값이 INF면 M원을 만들 수 없음
print(-1 if result == INF else result)