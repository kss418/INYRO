import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

MAX = 66
INF = 10**12
n = 0
st = []

def dnc(cy, cx, sz):
    flag = True # 모든 숫자가 같으면 1 아니면 0
    num = st[cy][cx] # 시작 숫자
    for i in range(cy, cy + sz):
        for j in range(cx, cx + sz):
            # 시작 숫자와 현재 숫자가 다르면 flag = 0
            if st[i][j] != num:
                flag = False
    if flag:
        print(num, end = '')
        return
    
    print("(", end = '')
    nsz = sz // 2
    
    # 분할
    for i in range(2):
        for j in range(2):
            dnc(cy + i * nsz, cx + j * nsz, nsz)
    print(")", end = '')


n = int(input().strip())
st = [input().strip() for _ in range(n)]
dnc(0, 0, n)

