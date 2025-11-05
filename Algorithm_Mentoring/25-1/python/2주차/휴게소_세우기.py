import sys
input = sys.stdin.readline

n, m, l = list(map(int, input().rstrip().split()))
a = list(map(int, input().rstrip().split()))
a.append(0) # 시작점 0
a.append(l) # 끝점 l
a.sort() # 정렬

def decision(cur):
    # 휴게소 사이의 거리의 최댓값을 cur로 만들기 위해
    # 필요한 추가 휴게소의 개수
    cnt = 0
    for i in range(1, n + 2):
        diff = a[i] - a[i - 1] # 휴게소의 거리
        cnt += diff // cur # (차이 // 최댓값) 만큼 추가로 휴게소를 설치
        if diff % cur == 0:
            cnt -= 1 # 차이가 최댓값의 배수면 1을 빼줌

    # 설치해야 하는 휴게소의 개수가 M 이하면 1
    # 아니면 0
    return cnt <= m

def minimization():
    # 정답의 범위는 1 ~ l
    lo = 1
    hi = l
    while(lo < hi):
        mid = (lo + hi) // 2 # 중간값
        # 결정 문제의 답이 1 이면
        # 정답은 [lo, mid]에 존재
        if(decision(mid)):
            hi = mid
        
        # 결정 문제의 답이 0 이면
        # 정답은 [mid + 1, hi]에 존재
        else:
            lo = mid + 1
    return lo

print(minimization())

