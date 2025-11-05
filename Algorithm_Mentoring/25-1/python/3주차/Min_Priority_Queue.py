import heapq

pq = []
heapq.heappush(pq, 1) # 1
print(pq[0])
heapq.heappush(pq, 3) # 1
print(pq[0])
heapq.heappush(pq, 2)

heapq.heappop(pq) # 1 제거
print(pq[0]) # 2

