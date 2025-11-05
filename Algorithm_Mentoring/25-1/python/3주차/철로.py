import sys
import heapq
input = sys.stdin.readline

n = int(input().rstrip())
a = []
pq = []

for _ in range(n):
    # e -> 끝점 s -> 시작점
    e, s = list(map(int, input().rstrip().split()))
    # 시작점이 끝점보다 크면 스왑
    if e < s:
        e, s = s, e
    a.append((e, s))

l = int(input().rstrip())
# 끝점을 기준으로 정렬
a.sort()
result = 0

for e, s in a:
    # 현재 시작점을 우선순위 큐에 넣음
    heapq.heappush(pq, s)
    # 우선순위 큐의 값과 현재 구간의 끝점의 차이가
    # L보다 크면 값 삭제
    while len(pq) != 0 and pq[0] < e - l:
        heapq.heappop(pq)
    # 우선순위 큐의 크기 최댓값으로 정답 갱신
    result = max(result, len(pq))

print(result)

