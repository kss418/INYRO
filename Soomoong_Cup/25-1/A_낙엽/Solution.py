import sys
input = sys.stdin.readline

N, A, B = map(int, input().split())
x_values = list(map(int, input().split()))
mx = max(x_values)

result = 0
sum = 0

while A > 0:
    # 오늘 밤에 낙엽이 쌓였을 때
    # B가 넘으면 낮에 낙엽을 치워줘야 함
    if sum + mx > B:
        # 정답에 1 추가
        result += 1
        sum = 0

    # 밤에 낙엽이 쌓임
    sum += mx
    A -= 1

print(result)
