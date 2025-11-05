import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
l = int(input().rstrip())
black = int(input().rstrip())

a = []
for _ in range(black):
    y, x = list(map(int, input().rstrip().split()))
    a.append((x, y))
a.sort()

def decision(cur):
    cnt = 0 # 사용한 정사각형의 개수
    last = int(-1e12) # 마지막으로 정사각형을 배치한 x 좌표
    for x, y in a:
        # y좌표가 정사각형보다 크면
        # 검은 칸을 가릴 수 없음
        if y > cur:
            return 0
        
        # 현재 x좌표가 이미 배치한 정사각형
        # 안에 들어오면 이미 막힌 검은 칸
        if x - last + 1 <= cur:
            continue
        last = x
        cnt += 1

    # 정사각형을 L개 이하로 사용 했으면
    # 검은 칸을 다 막을 수 있음
    return cnt <= l

def minimization():
    lo = 1
    # 범위의 최댓값은 1e6
    hi = int(2e6)
    while(lo < hi):
        mid = (lo + hi) // 2
        if(decision(mid)):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimization())

