import sys
input = sys.stdin.readline
INF = 1e12

def run():
    N = int(input().strip())
    A = [0] + list(map(int, input().split()))
    B = [0] + list(map(int, input().split()))

    dp = [[INF]*101 for _ in range(N+1)]
    mn = [INF] * (N+1)

    dp[0][0] = 0
    mn[0] = 0

    # DP 식 계산
    for i in range(1, N+1):
        # j == 0, 현재 서 있는 상태이므로
        # 전의 모든 DP에서 서 있을 때 드는 비용을 더한 값의 최솟값
        dp[i][0] = min(dp[i][0], mn[i-1] + B[i])

        # j == A[i], 처음으로 앉은 상태이므로
        # 전의 모든 DP에서 앉아 있을 때 드는 비용을 더한 값의 최솟값
        ai = A[i]
        dp[i][ai] = min(dp[i][ai], mn[i-1] + ai)

        # j != A[i] && j != 0, 이미 앉아 있는 상태이므로
        # 앉아 있는 상태에서 드는 비용을 더함
        for j in range(1, 101):
            if j == ai:
                continue
            dp[i][j] = min(dp[i][j], dp[i-1][j] + j)

        # 최솟값 전처리
        mn[i] = min(dp[i])

    print(mn[N])

t = int(input().strip())
for _ in range(t):
    run()
    t -= 1
