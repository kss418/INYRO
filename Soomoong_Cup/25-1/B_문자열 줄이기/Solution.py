import sys
input = sys.stdin.readline

def run():
    s = input().strip()

    # 정답 문자열 길이로 초기화
    result = len(s)
    for i in range(len(s) - 1):
        # 인접한 두 문자가 같으면
        # 항상 길이를 1로 줄일 수 있음
        if s[i] == s[i + 1]:
            result = 1

    print(result)

t = int(input())
while t > 0:
    run()
    t -= 1
