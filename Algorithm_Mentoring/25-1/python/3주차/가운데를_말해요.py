import sys
import heapq
input = sys.stdin.readline

pq1 = []
pq2 = []

n = int(input().rstrip())
for i in range(n):
    x = int(input().rstrip())

    # 인덱스가 0 부터 시작
    # 홀수 번째에는 최대 우선순위 큐에 삽입
    if i % 2 == 0:
        heapq.heappush(pq1, -x)
    # 짝수 번째에는 최소 우선순위 큐에 삽입
    else:
        heapq.heappush(pq2, x)

    # 최대 우선순위 큐의 값이 최소 우선순위 큐의 값보다 크면
    if len(pq2) != 0 and -pq1[0] > pq2[0]:
        t1 = -pq1[0]
        t2 = pq2[0]
        # 서로 스왑해 줌
        heapq.heappop(pq1)
        heapq.heappop(pq2)
        heapq.heappush(pq1, -t2)
        heapq.heappush(pq2, t1)
    
    # 최대 우선순위 큐의 값이 중간 값
    print(-pq1[0])

