import sys
import heapq
input = sys.stdin.readline

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    a = list(map(int, input().rstrip().split()))
    result = 0

    # 최소 우선순위 큐
    pq = []
    # 먼저 모든 값을 우선순위 큐에 넣음
    for i in a:
        heapq.heappush(pq, i)
    
    # 우선순위 큐의 크기가 1이 될 때 까지 반복
    while len(pq) > 1:
        # 제일 작은 수
        fi = heapq.heappop(pq)
        # 두 번째로 작은 수
        se = heapq.heappop(pq)

        # 합쳐서 우선순위 큐에 다시 넣음
        heapq.heappush(pq, fi + se)
        # 정답에 추가
        result += fi + se

    print(result)

