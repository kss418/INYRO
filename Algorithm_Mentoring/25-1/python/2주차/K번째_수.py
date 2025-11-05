import sys
input = sys.stdin.readline

n = int(input().rstrip())
m = int(input().rstrip())

def decision(cur):
    cnt = 0 # cur보다 작은 수의 개수
    for i in range(1, n + 1):
        # i번째 열의 cur보다 작은 수의 개수를 더함
        cnt += min(cur // i, n)
    return cnt >= m

def minimization():
    lo = 1
    # 범위의 최댓값은 1e10
    hi = int(2e10)
    while lo < hi:
        mid = (lo + hi) // 2
        if decision(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimization())