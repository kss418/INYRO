import sys
import heapq
input = sys.stdin.readline

pq = []
n = int(input().rstrip())
for _ in range(n):
    x = int(input().rstrip())
    
    if x != 0:
        # 우선순위 큐에 x 삽입
        heapq.heappush(pq, x)
    else:
        # 우선순위 큐가 비어있으면
        if len(pq) == 0:
            print(0) # 0 출력

        # 아니면
        else:
            # 최솟값 출력 및 값 삭제
            print(heapq.heappop(pq))