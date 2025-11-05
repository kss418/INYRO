import sys
import heapq
input = sys.stdin.readline

n = int(input().rstrip())
a = []
for _ in range(n):
    x, y = list(map(int, input().rstrip().split()))
    a.append((x, y))
en, fuel = list(map(int, input().rstrip().split()))
pq = []

a.append((en, 0)) # 마을도 포함
a.sort() # 거리가 가까운 순으로 정렬
result = 0

for x, y in a:
    # 현재 주유소의 거리가 갈 수 있는 거리보다 멀면
    while x > fuel:
        # 비축해둔 연료가 없으면
        # 마을까지 갈 수 없으므로 -1
        if len(pq) == 0:
            print(-1)
            exit()

        result += 1
        # 가장 많은 연료부터 소모
        fuel += -heapq.heappop(pq)

    # 연료를 비축해둠
    heapq.heappush(pq, -y)

print(result)
