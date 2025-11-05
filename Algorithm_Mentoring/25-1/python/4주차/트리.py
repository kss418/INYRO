import sys
input = sys.stdin.readline

n = int(input().rstrip())
p = list(map(int, input().rstrip().split()))
a = [[] for _ in range(55)]
root = 0
result = 0

def dfs(cur):
    global result
    # 현재 노드가 삭제된 노드면 return
    if cur == m:
        return
    for nxt in a[cur]:
        dfs(nxt)
    
    # 현재 노드의 자손이 없거나
    # 자손이 1개고 자손이 삭제된 노드면 정답 +1
    if len(a[cur]) == 0 or (len(a[cur]) == 1 and a[cur][0] == m):
        result += 1

for i in range(len(p)):
    # 부모가 -1이면 루트 노드
    if p[i] == -1:
        root = i 
    # 아니면 간선 추가
    else:
        a[p[i]].append(i)
m = int(input().rstrip())

dfs(root)
print(result)
