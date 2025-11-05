import sys
input = sys.stdin.readline

n = int(input().rstrip())
a = []
a.append(0)
for _ in range(n):
    num = int(input().rstrip())
    a.append(num)

dp = [[0, 0] for _ in range(303)]

# Base Case
dp[1][0] = a[1]
if(n >= 2):
    dp[2][0] = a[2]
    dp[2][1] = a[1] + a[2]

for i in range(3, n + 1):
    # 전의 계단을 밟았으면 전의 계단에서 점화식 전이
    dp[i][1] = dp[i - 1][0] + a[i]

    # 전의 계단을 밟지 않았으면 2칸 전의 계단에서 점화식 전이
    dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + a[i]

# 둘 중 큰 값이 정답
print(max(dp[n][0], dp[n][1]))

