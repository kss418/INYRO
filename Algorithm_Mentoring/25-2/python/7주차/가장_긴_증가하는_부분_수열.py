import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

MAX = 1010
n = int(input())
a = [0] + list(map(int, input().split()))
dp = [-1] * MAX

def solve(cur):
    if dp[cur] != -1:
        return dp[cur]
    dp[cur] = 0

    for i in range(cur):
        # 이전의 값이 크거나 같으면 증가하는 부분 수열이 아님
        if a[i] >= a[cur]:
            continue
        # 이전의 수열 길이에 +1
        dp[cur] = max(dp[cur], solve(i) + 1)

    return dp[cur]

result = 0
dp[0] = 0

# 1 ~ n의 DP값 중 최댓값이 정답
for i in range(1, n + 1):
    result = max(result, solve(i))

print(result)
