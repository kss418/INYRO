import sys
input = sys.stdin.readline

def run():
    # 문자열로 입력 받음
    N = input().strip()
    sum = 0

    # 각 자리의 합을 더함
    for i in N:
        sum += int(i)

    # 6의 배수이려면 동시에 
    # 2의 배수이고 3의 배수여야 함

    # 2의 배수인 조건 -> 마지막 자리의 수가 짝수
    # 3의 배수인 조건 -> 모든 자리 수의 합이 3의 배수
    print("Yes" if (int(N[-1]) % 2 == 0 and sum % 3 == 0) else "No")

t = int(input())
while t > 0:
    run()
    t -= 1
