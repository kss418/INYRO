import sys
from collections import deque
input = sys.stdin.readline

MAX = 1010
INF = 10**12

n, m = map(int, input().split())
ind = [0] * MAX
a = [0] * MAX
adj = [[] for _ in range(MAX)]
result = []
q = deque()

for _ in range(m):
    data = list(map(int, input().split()))
    sz = data[0]
    for i in range(1, sz + 1):
        a[i] = data[i]

    for i in range(1, sz):
        # a[i] -> a[i + 1] 인 간선
        adj[a[i]].append(a[i + 1])
        ind[a[i + 1]] += 1

for i in range(1, n + 1):
    if ind[i] == 0:
        q.append(i)

# 위상정렬
while q:
    cur = q.popleft()
    result.append(cur)
    for nxt in adj[cur]:
        ind[nxt] -= 1
        if ind[nxt] == 0:
            q.append(nxt)

flag = 1
for i in range(1, n + 1):
    # indegree가 0이 아닌 값이 있으면
    # 사이클이 존재 -> 위상 정렬 불가
    if ind[i] != 0:
        flag = 0
        break

if flag:
    sys.stdout.write("\n".join(map(str, result)))
else:
    sys.stdout.write("0")
