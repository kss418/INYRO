import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def solve(cy, cx):
    if dp[cy][cx] != -1:
        return dp[cy][cx]

    # Base Case
    if cy == 1 and cx == 1:
        dp[cy][cx] = 1
        return 1

    ret = 0
    for i in range(4):
        ny = cy + dy[i]
        nx = cx + dx[i]
        # 격자 밖이면 건너 뜀
        if not (1 <= ny <= n and 1 <= nx <= m):
            continue
        
        # 내리막 길이 아니면 건너 뜀
        if a[ny][nx] <= a[cy][cx]:
            continue
        ret += solve(ny, nx)

    dp[cy][cx] = ret
    return ret

n, m = map(int, input().split())
a  = [[0] * (m+1) for _ in range(n+1)]
dp = [[-1] * (m+1) for _ in range(n+1)]

for i in range(1, n+1):
    row = list(map(int, input().split()))
    for j in range(1, m+1):
        a[i][j] = row[j-1]

print(solve(n, m))
