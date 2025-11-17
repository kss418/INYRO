import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

MAX = 10101
dp = [[-1] * 4 for _ in range(MAX)]

def solve(cur, mx):
    if cur < 0:
        return 0
    
    ret = dp[cur][mx]
    if ret != -1:
        return ret
    
    ret = 0
    if cur == 0:
        dp[cur][mx] = 1 if mx == 1 else 0
        return dp[cur][mx]
    
    for i in range(1, mx + 1):
        ret += solve(cur - mx, i)

    dp[cur][mx] = ret
    return ret

def run():
    n = int(input().strip())
    result = 0
    for i in range(1, 4):
        result += solve(n, i)
    print(result)

t = int(input().strip())
for _ in range(t):
    run()
