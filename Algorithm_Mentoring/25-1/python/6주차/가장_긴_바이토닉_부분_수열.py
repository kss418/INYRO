import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

def solve(cur, cnt):
    if dp[cur][cnt] != -1:
        return dp[cur][cnt]
    
    ret = 1
    # 감소하는 상태
    if cnt == 1:
        for i in range(1, cur):
            # 이전 값이 현재 값보다 작으면 건너 뜀
            if a[i] <= a[cur]:
                continue
            ret = max(ret, solve(i, 0) + 1, solve(i, 1) + 1)
    # 증가하는 상태
    else:
        for i in range(1, cur):
            # 이전 값이 현재 값보다 크면 건너 뜀
            if a[i] >= a[cur]:
                continue
            ret = max(ret, solve(i, 0) + 1)

    dp[cur][cnt] = ret
    return ret

n = int(input())
A = list(map(int, input().split()))
a = [0] + A

dp = [[-1] * 2 for _ in range(n + 1)]

ans = 0
for i in range(1, n + 1):
    # DP[i][0], DP[i][1]중 최댓값이 정답
    ans = max(ans, solve(i, 0), solve(i, 1))

print(ans)

