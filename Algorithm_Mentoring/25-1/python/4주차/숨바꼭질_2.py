import sys
from collections import deque
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
d = [-1] * 101010
cnt = [0] * 101010

# 방문 배열 초기화
for i in range(101010):
    d[i] = -1

q = deque()
def bfs(st):
    q.append(st)
    d[st] = 0
    cnt[st] = 1

    while len(q) != 0:
        cur = q.popleft()
        for nxt in (cur + 1, cur - 1, 2 * cur):
            # 다음 정점이 점 밖에 있으면 건너 뜀
            if nxt < 0 or nxt >= 101010:
                continue

            # 다음 정점이 방문하지 않은 정점이면
            if d[nxt] == -1:
                # 큐에 삽입하고 거리 배열 +1
                q.append(nxt)
                d[nxt] = d[cur] + 1
            
            # 다음 정점과의 거리가 최단거리이면
            # 현재 정점까지 가는 경우의 수를 더함
            if d[nxt] == d[cur] + 1:
                cnt[nxt] += cnt[cur]

bfs(n)
print(d[m])
print(cnt[m])