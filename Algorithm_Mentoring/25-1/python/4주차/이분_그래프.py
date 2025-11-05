import sys
sys.setrecursionlimit(10**6)
from collections import deque
input = sys.stdin.readline

result = 0

def add(s, e):
    # 양방향 간선 추가
    a[s].append(e)
    a[e].append(s)

def dfs(cur, num):
    global result
    # 현재 정점의 번호 설정
    v[cur] = num

    for nxt in a[cur]:
        # 다음 정점을 방문 했으면
        if v[nxt] != -1:
            # 배치할 번호와 이미 배치 된 번호가 다르면 NO
            if v[nxt] != num ^ 1:
                result = 0
            continue
        # 번호를 바꿔서 탐색
        dfs(nxt, num ^ 1)
            
t = int(input().rstrip())
for _ in range(t):
    # 방문 배열과 간선 리스트 초기화
    v = [-1] * 20101
    a = [[] for _ in range(20101)]
    result = 1

    n, m = list(map(int, input().rstrip().split()))
    # 간선 추가
    for _ in range(m):
        s, e = list(map(int, input().rstrip().split()))
        add(s, e)
    
    for i in range(1, n + 1):
        # 방문을 했으면 넘어 감
        if v[i] != -1:
            continue
        dfs(i, 0)
    
    print("YES" if result == 1 else "NO")