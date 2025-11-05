import sys
input = sys.stdin.readline

def solve(l, r):
    ret = 0
    # L 부터 R 까지 순회
    for i in range(l, r+1):
        if S[i-1] != 'S':
            continue

        # 현재 s[i]가 'S' 이면
        for j in range(i+1, r+1):
            if S[j-1] != 'M':
                continue
            # i 이후의 'M'의 개수를 더함
            ret += 1

    return ret

def run():
    global S
    S, M = input().split()

    M = int(M)
    while M:
        L, R = map(int, input().split())
        print(solve(L, R))
        M -= 1

t = int(input())
while t:
    run()
    t -= 1
