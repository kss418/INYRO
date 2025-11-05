n = int(input())

stack = []
result = []
use = 1 # 스택에 삽입 할 수

for i in range(n):
    x = int(input()) # 현재 출력해야 하는 수
    while(use <= x): # X가 삽입이 안 되었으면
        stack.append(use) # 스택에 수 삽입
        use += 1
        result.append('+') # 정답에 + 추가
    
    # 스택이 비었거나 스택의 값이 X가 아니면
    if(len(stack) == 0 or stack[-1] != x): 
        print("NO")
        exit(0)
    
    stack.pop() 
    result.append('-') # 정답에 - 추가

for i in result:
    print(i)
    
