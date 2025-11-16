import sys
input = sys.stdin.readline

mod = 10 ** 9 + 9
dp = [-1] * 1010101

# Base Case
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(3, 1010101):
    # 점화식은 f(n - 1) + f(n - 2) + f(n - 3)
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    print(dp[n])

    