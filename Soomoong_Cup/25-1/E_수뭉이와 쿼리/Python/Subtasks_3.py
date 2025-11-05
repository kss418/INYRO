import sys
input = sys.stdin.readline

MAX = 20101
S = ""
N = M = 0
s_pre = [0] * MAX
m_pre = [0] * MAX
sm_pre = [0] * MAX

# 누적 합 계산
def init():
    for i in range(1, N + 1):
        s_pre[i] = s_pre[i - 1]
        if S[i - 1] == 'S':
            s_pre[i] += 1

    for i in range(1, N + 1):
        m_pre[i] = m_pre[i - 1]
        sm_pre[i] = sm_pre[i - 1]
        if S[i - 1] == 'M':
            # "SM" 쌍의 개수는 현재 S[i]가 'M'일 때
            # 이전의 'S'의 개수를 모두 더해준 값
            sm_pre[i] += s_pre[i]
            m_pre[i] += 1

# "SM" 쌍 계산
def solve(l, r):
    # L 이전의 "SM" 쌍의 개수는
    # L 이전의 'S' 개수와 L ~ R 사이의 'M' 개수를 곱해준 값

    # L ~ R 의 "SM" 쌍의 개수에서 L 이전의 "SM" 쌍의 개수를 빼줘야 함
    return sm_pre[r] - sm_pre[l - 1] - s_pre[l - 1] * (m_pre[r] - m_pre[l - 1])

def run():
    global S, N, M
    parts = input().split()
    S, M = parts[0], int(parts[1])
    N = len(S)
    init()
    for _ in range(M):
        L, R = map(int, input().split())
        print(solve(L, R))

t = int(input())
for _ in range(t):
    run()
