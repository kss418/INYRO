import sys
input = sys.stdin.readline
n = int(input().rstrip())
a = [int(input().rstrip()) for _ in range(n)]

st = []
result = 0

for i in a:
    # 이전의 값이 현재 값보다 작을 때
    while len(st) and st[-1][0] < i:
        # 정답에 이전 값의 개수만큼 더함
        # 작은 값들은 더 이상 다음 값들을 만날 수 없으므로
        # 스택에서 빼줌
        result += st[-1][1]
        st.pop()

    # 스택이 비었거나 현재 값이랑 다르면 한 개 추가
    if len(st) == 0 or st[-1][0] != i:
        st.append((i, 1))
    # 이전 값이랑 현재 값이랑 같으면
    # 이전 값에 1을 추가해서 넣어줌
    else:
        num = st[-1][1] + 1
        st.pop()
        st.append((i, num))
        # 같은 값들끼리는 서로 볼 수 있으므로 정답에 더함
        result += num - 1
 
    # 스택의 값이 2개 이상이면 정답에 1 추가
    if(len(st) >= 2):
        result += 1

print(result) 

