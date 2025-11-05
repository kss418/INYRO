import sys
import heapq
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))

def decision(cur):
    # 최소 시간 출력
    # cur개 만큼의 공정 라인 사용 가능
    pq = [0] * cur

    mx = 0 # 공정 라인 사용 시간 최댓값
    for i in a:
        # 제일 적은 공정 라인 사용 시간
        # 현재 제작 시간을 더함
        now = heapq.heappop(pq) + i
        heapq.heappush(pq, now)
        mx = max(mx, now)
    
    # 공정 라인 사용 시간 최댓값이 M보다 작으면
    # cur개의 라인으로 M시간 내에 제작 가능
    return mx <= m

def maximization():
    lo = 1
    hi = int(2e5)
    while lo < hi:
        mid = (lo + hi) // 2
        if(decision(mid)):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(maximization())
