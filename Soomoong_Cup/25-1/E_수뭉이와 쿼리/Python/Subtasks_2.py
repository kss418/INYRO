import sys
input = sys.stdin.readline

MAX = 20101
S = ""
N = M = 0
pre = [0] * MAX

# 누적합 계산
def init():
    for i in range(1, N + 1):
        pre[i] = pre[i - 1]
        if S[i - 1] == 'S':
            pre[i] += 1

# "SM" 쌍 계산
def solve(l, r):
    ret = 0
    for i in range(l, r + 1):
        if S[i - 1] == 'S':
            continue
        # 현재 S[i]가 'M'이면
        # L ~ i 까지의 'S'의 개수를 더함
        ret += pre[i] - pre[l - 1]
    return ret

def run():
    global S, N, M
    parts = input().split()
    
    S, M = parts[0], int(parts[1])
    N = len(S)
    init()
    while M > 0:
        L, R = map(int, input().split())
        print(solve(L, R))
        M -= 1

t = int(input())
while t > 0:
    run()
    t -= 1
