import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input().strip())
a = list(map(int, input().split()))
m = int(input().strip())
b = list(map(int, input().split()))

MAX = 33
MID = 50101

dp = [[-1] * 101010 for _ in range(MAX)]

def solve(cur, num):
    if num < 0 or num >= 101010:
        return 0
    
    if dp[cur][num] != -1:
        return dp[cur][num]
    
    # 추를 하나도 놓지 않았으면 무게는 0 이여야 함
    if cur == -1:
        return 1 if num == MID else 0
    
    ret = 0

    # 추를 사용하지 않음
    ret = max(ret, solve(cur - 1, num))

    # 추를 구슬과 같은 곳에 놓음
    ret = max(ret, solve(cur - 1, num + a[cur]))

    # 추를 구슬 반대 편에 놓음
    ret = max(ret, solve(cur - 1, num - a[cur]))

    dp[cur][num] = ret
    return ret

for i in b:
    print("Y" if solve(n - 1, i + MID) else "N", end = " ")