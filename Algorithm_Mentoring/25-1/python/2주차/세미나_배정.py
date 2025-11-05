import sys
input = sys.stdin.readline

n, m = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))
a.sort()
num = [0] * 201010

def decision(cur):
    # 현재 사용중인 세미나의 시작날의 최댓값
    last = 0
    for i in range(1, n + 1):
        # K개의 세미나실을 아직 다 안썼다면
        # 시작날을 max(a[i - 1] - m + 1, 1)로 지정
        if(i <= cur):
            last = max(a[i - 1] - m + 1, 1)

        # K개의 세미나실을 다 썼다면
        # K개의 인덱스 전의 세미나의 시작날에 M을 더함
        else:
            last = max(a[i - 1] - m + 1, num[i - cur - 1] + m, 1)

        # 세미나의 시작날 저장
        num[i - 1] = last

        # 세미나의 시작날이 지정한 날보다 늦으면
        # K개의 세미나실로 세미나를 진행할 수 없음
        if a[i - 1] - num[i - 1] < 0:
            return 0
        
    # 아니면 K개의 세미나실로 진행 할 수 있음
    return 1


def minimization():
    lo = 1
    # 구간의 최댓값은 2e5
    hi = 201010
    while lo < hi:
        mid = (lo + hi) // 2
        if(decision(mid)):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(minimization())
