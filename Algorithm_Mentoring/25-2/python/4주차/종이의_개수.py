import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
cnt = [0, 0, 0]

def dnc(cy, cx, sz):
    flag = True # 모든 종이가 같으면 1 아니면 0
    num = a[cy][cx] # 시작 종이의 숫자

    for i in range(cy, cy + sz):
        for j in range(cx, cx + sz):
            # 시작 종이와 현재 종이가 다르면 flag = 0 
            if a[i][j] != num:
                flag = False

    # 모든 종이가 같으면 시작 종이의 개수를 1 증가
    # 및 재귀 함수 종료
    if flag:
        cnt[num + 1] += 1
        return

    # 다음 종이의 크기
    nsz = sz // 3
    for i in range(3):
        for j in range(3):
            # 분할
            dnc(cy + i * nsz, cx + j * nsz, nsz)

dnc(0, 0, n)
print(cnt[0])
print(cnt[1])
print(cnt[2])
