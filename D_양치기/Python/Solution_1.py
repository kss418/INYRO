import sys
input = sys.stdin.readline

MAX = 101010
a = [(0, 0)] * MAX
st = []

N = int(input())
for i in range(1, N+1):
    x, y = map(int, input().split())
    a[i] = (x, y)

# 위치 순서대로 정렬
a = sorted(a[1:N+1])

slow = 10**12
result = 0
for i in range(N-1, -1, -1):
    # 현재 양의 속도가 가장 느린 양의 속도보다 느리면
    # 정답에 1 추가
    if a[i][1] <= slow:
        result += 1

    # 가장 느린 양의 속도 갱신
    slow = min(slow, a[i][1])

print(result)
