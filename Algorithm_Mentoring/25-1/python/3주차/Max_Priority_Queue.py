import heapq

pq = []
heapq.heappush(pq, -1) # 1
print(-pq[0])
heapq.heappush(pq, -3) # 3
print(-pq[0])
heapq.heappush(pq, -2)

heapq.heappop(pq) # 3 제거
print(-pq[0]) # 2

