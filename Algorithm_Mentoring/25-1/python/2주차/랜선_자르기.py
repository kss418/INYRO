import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = [int(input().rstrip()) for _ in range(n)]

def decision(cur):
    cnt = 0 # 만들 수 있는 랜선의 개수
    for i in a:
        # 랜선의 길이를 cur 만큼 자를 때
        # a[i] // cur 만큼 랜선이 나옴
        cnt += i // cur

    # 만들 수 있는 랜선의 개수가 M 이상이면 1 아니면 0 반환
    return cnt >= m

def maximization():
    # 정답의 범위는 1 ~ 2^31 - 1
    lo = 1
    hi = 2 ** 31 - 1
    while lo < hi:
        mid = (lo + hi + 1) // 2 # 중간값
        # 결정 문제의 답이 1 이면
        # 정답은 [mid, hi]에 존재
        if(decision(mid)):
            lo = mid

        # 결정 문제의 답이 0 이면
        # 정답은 [lo, mid - 1]에 존재
        else:
            hi = mid - 1
    return lo

print(maximization())

