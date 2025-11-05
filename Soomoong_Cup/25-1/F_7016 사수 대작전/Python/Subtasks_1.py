import sys
input = sys.stdin.readline

def run():
    N = int(input())
    A = [0] * (N + 1)
    B = [0] * (N + 1)

    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    result = 1e12
    # 브루트포스
    # 각 비트가 1이면 앉기, 0이면 서 있기
    for mask in range(1 << N):
        mn = 1e12
        now = 0
        for j in range(N):
            # j번째 정류장에서 앉아있다면 이전까지의 A 중 최솟값을 더함
            if mask & (1 << j):
                mn = min(mn, A[j])
                now += mn

            # 서 있을 때는 mn 초기화 후 B 비용을 더함
            else:
                mn = 1e12
                now += B[j]

        # 최솟값 갱신
        result = min(result, now)

    print(result)

t = int(input())
while t:
    run()
    t -= 1

