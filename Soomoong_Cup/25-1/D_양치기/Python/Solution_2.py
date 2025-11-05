import sys
input = sys.stdin.readline

MAX = 101010
a = [(0, 0)] * MAX
st = []

N = int(input())
for i in range(1, N+1):
    # 위치와 속도 입력
    a[i] = tuple(map(int, input().split()))

# 위치 순서대로 정렬
a = sorted(a[1:N+1])

for i in range(N):
    # 스택의 양의 속도가 현재 양의 속도보다 빠르면
    # 스택에서 제거
    while st and st[-1] > a[i][1]:
        st.pop()

    # 스택에 삽입
    st.append(a[i][1])

# 스택에 남아있는 양의 수가 정답
print(len(st))
