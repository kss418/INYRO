import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

MOD = 10**9
dp = [[-1] * 10 for _ in range(1010)]

def solve(cur, num):
    # 수가 음수거나 한 자리 수가 아니면 0 반환
    if num < 0 or num > 9:
        return 0
    
    if dp[cur][num] != -1:
        return dp[cur][num]
    
    # 0으로 시작하는 계단 수는 계단 수가 아님
    if cur == 1:
        return 1 if num != 0 else 0

    # 이전의 수와 현재 수가 한개 차이가 나야 함
    dp[cur][num] = solve(cur - 1, num - 1) + solve(cur - 1, num + 1)
    dp[cur][num] %= MOD

    return dp[cur][num]

n = int(input().rstrip())

result = 0
# 0 ~ 9의 합이 정답
for i in range(10):
    result += solve(n, i)
    result %= MOD

print(result)