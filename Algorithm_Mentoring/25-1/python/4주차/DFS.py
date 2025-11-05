import sys
input = sys.stdin.readline
v = [0] * 10
a = [[] for _ in range(10)]

def add(s, e):
    # 양방향 간선 추가
    a[s].append(e)
    a[e].append(s)

def dfs(cur):
    # 방문한 정점으로 표시
    v[cur] = 1
    print(cur)

    for nxt in a[cur]:
        # 다음 정점이 방문한 정점이면 넘어 감
        if v[nxt] == 1:
            continue
        dfs(nxt)

add(1, 2)
add(2, 4)
add(2, 5)
add(1, 3)
add(3, 6)
add(6, 7)

dfs(1)
