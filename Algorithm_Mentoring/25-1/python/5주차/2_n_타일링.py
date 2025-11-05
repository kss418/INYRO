import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

dp = [-1] * 1010
mod = 10007
dp[1] = 1
dp[2] = 2

def solve(cur):
    # 현재 값이 이미 계산되었으면 반환
    if dp[cur] != -1:
        return dp[cur]
    
    # 점화식은 f(n - 1) + f(n - 2)
    dp[cur] = (solve(cur - 1) + solve(cur - 2)) % mod
    return dp[cur]

n = int(input().rstrip())
print(solve(n))

