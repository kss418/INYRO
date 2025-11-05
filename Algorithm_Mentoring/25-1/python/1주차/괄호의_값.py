import sys
input = sys.stdin.readline

def chk(s):
    # 올바른 괄호열이면 True 아니면 False 반환
    st = []
    for i in s:
        # 여는 괄호면 스택에 추가
        if i == '(' or i == '[':
            st.append(i)
        else:
            # 매칭할 여는 괄호가 없으면 틀린 괄호열
            if len(st) == 0:
                return False
            
            # 매칭할 여는 괄호가 다른 종류의 괄호면 틀린 괄호열
            if i == ')' and st[-1] == '[':
                return False
            elif i == ']' and st[-1] == '(':
                return False
            
            # 여는 괄호랑 매칭 했으므로 여는 괄호를 스택에서 제거
            st.pop()
    
    # 매칭 되지 않은 괄호가 있으면 틀린 괄호열
    # 아니면 올바른 괄호열
    return len(st) == 0

s = input().rstrip()
if not chk(s): # 틀린 괄호열이면 0 출력
    print(0)
    exit(0)

result = [0] * 31
cnt = 0 # 현재 깊이

for i in s:
    if i == '(' or i == '[': # 여는 괄호면
        cnt += 1 # 깊이 증가
    elif i == ')': # 닫는 괄호면
        cnt -= 1 # 깊이 감소
        # 이전 값에 2를 곱해서 더함
        # 0 이면 1로 취급
        result[cnt] += 2 * max(result[cnt + 1], 1)
        result[cnt + 1] = 0 # 이전 값 초기화
    else:
        cnt -= 1 # 깊이 감소
        # 이전 값에 3을 곱해서 더함
        # 0 이면 1로 취급
        result[cnt] += 3 * max(result[cnt + 1], 1)
        result[cnt + 1] = 0 # 이전 값 초기화

# 정답은 인덱스 0에 있음
print(result[0])
