import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

inf = 1000000000
n = int(input().rstrip())
l = [0] * (n + 1)
r = [0] * (n + 1)
idx = [0] * (n + 1)
root = [1] * (n + 1)
mx = [0] * (n + 1)
mn = [inf] * (n + 1)
num = 0

def dfs(cur, dep):
    global num
    # 왼쪽 자식이 있으면 DFS
    if l[cur] != -1:
        dfs(l[cur], dep + 1)

    # 왼쪽 자식 탐색이 끝났으면
    # 현재 정점에 번호 부여
    num += 1
    mn[dep] = min(mn[dep], num)
    mx[dep] = max(mx[dep], num)

    # 오른쪽 자식이 있으면 DFS
    if r[cur] != -1:
        dfs(r[cur], dep + 1)

for _ in range(n):
    arr = list(map(int, input().rstrip().split()))
    idx = arr[0]
    l[idx], r[idx] = arr[1], arr[2]
    
    # 누군가의 자식 정점이면 루트 노드가 아님
    if l[idx] != -1:
       root[l[idx]] = 0
    if r[idx] != -1:
        root[r[idx]] = 0

for i in range(1, n + 1):
    # 루트 노드가 아니면 건너 뜀
    if root[i] == 0:
        continue
    dfs(i, 1)

result = 0
diff = 0

for i in range(1, n + 1):
    # 현재 깊이의 너비가 원래 너비보다 크면
    if mx[i] - mn[i] + 1 > diff:
        # 값 갱신
        diff = mx[i] - mn[i] + 1
        result = i

print(f"{result} {diff}")