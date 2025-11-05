import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

INF = 1e12
MAX = 30101

A = [0] * MAX
B = [0] * MAX
dp = [[-1] * 101 for _ in range(MAX)]

# DP 식 계산
def solve(cur, mx):
    ret = dp[cur][mx]
    if ret != -1:
        return ret
    ret = INF
    dp[cur][mx] = ret

    if cur == 0:
        return ret

    # j == 0, 현재 서 있는 상태이므로
    # 전의 모든 DP에서 서 있을 때 드는 비용을 더한 값의 최솟값
    if mx == 0:
        for i in range(101):
            ret = min(ret, solve(cur - 1, i) + B[cur])
    else:
        # j == A[cur], 처음으로 앉은 상태이므로
        # 전의 모든 DP에서 앉아 있을 때 드는 비용을 더한 값의 최솟값
        if mx == A[cur]:
            for i in range(101):
                ret = min(ret, solve(cur - 1, i) + A[cur])
        # j != A[cur] && j != 0, 이미 앉아 있는 상태이므로
        # 앉아 있는 상태의 드는 비용을 더함
        else:
            ret = min(ret, solve(cur - 1, mx) + mx)

    dp[cur][mx] = ret
    return ret

def run():
    # DP 값 초기화
    for i in range(MAX):
        for j in range(101):
            dp[i][j] = -1
    dp[0][0] = 0

    N = int(input().rstrip())

    tmp = list(map(int, input().split()))
    for i in range(1, N + 1):
        A[i] = tmp[i - 1]

    tmp = list(map(int, input().split()))
    for i in range(1, N + 1):
        B[i] = tmp[i - 1]

    result = INF
    for i in range(101):
        result = min(result, solve(N, i))
    print(result)

t = int(input().rstrip())
for _ in range(t):
    run()
