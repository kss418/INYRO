import sys
input = sys.stdin.readline

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    s = input().rstrip()
    st = []

    for i in s:
        st.append(i)
        cnt = 0 # 현재 연산 횟수

        # 스택의 마지막 값이 ABB 이면
        while len(st) >= 3 and st[-3] == 'A' and st[-2] == 'B' and st[-1] == 'B':
            for _ in range(3):
                st.pop() # ABB 제거
            
            cnt += 1 # 연산 횟수 1 증가
            st.append('B') # B 추가

        for _ in range(cnt):
            st.append('A') # 연산 횟수만큼 A 추가
        
    print(*st, sep = '')


