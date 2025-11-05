import sys
import heapq
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = []
for _ in range(n):
    x = int(input().rstrip())
    a.append(x)

b = []
for _ in range(m):
    l, r = list(map(int, input().rstrip().split()))
    b.append((l, r))

# 정렬
a.sort()
b.sort()

idx = 0 # 현재 보는 구간의 인덱스
result = 0
pq = []

for i in a:
    # 현재 구간을 끝까지 안봤고
    # 구간의 시작점이 배열의 값 이하면
    while idx < m and b[idx][0] <= i:
        # 우선순위 큐에 삽입
        heapq.heappush(pq, b[idx][1])
        idx += 1 # 보는 구간의 인덱스 1 증가
    
    # 우선순위 큐의 값이 현재 배열의 값보다 작으면
    # 매칭 할 수 없으므로 삭제
    while len(pq) != 0 and pq[0] < i:
        heapq.heappop(pq)
    
    # 우선순위 큐가 비어있지 않으면
    if len(pq) != 0:
        # 매칭 가능
        result += 1
        heapq.heappop(pq)
    
print(result)


