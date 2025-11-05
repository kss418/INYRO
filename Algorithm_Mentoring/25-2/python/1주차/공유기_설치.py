import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = []
for _ in range(n):
    x = int(input().rstrip())
    a.append(x)
a.sort() 

def decision(cur):
    # cnt -> 설치한 공유기 개수
    # last -> 마지막으로 설치한 공유기 위치
    cnt = 0
    last = -1e12 # last는 음의 무한대로 초기화

    for i in a:
        # 마지막으로 설치한 공유기의 위치와
        # 현재 위치의 차이가 K보다 작다면 건너 뜀
        if i - last < cur:
            continue
        last = i
        cnt += 1

    # 설치한 공유기 개수가 M 이상이면
    # 공유기 거리의 차이의 최솟값을 K로 만들 수 있음
    return cnt >= m

def maximization():
    # 최솟값은 1, 최댓값은 1e9
    # 실수 오차 있을 수 있으니 넉넉하게 2e9로 잡음
    lo = 1
    hi = int(2e9)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if decision(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo

print(maximization())

