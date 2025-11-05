import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

MAX = 55
len = [0] * MAX
mx = 0

def dnc(cur, sz):
    # Base Case
    if not sz:
        return 'm' if cur == 1 else 'o'
    
    # 앞쪽 구간이면 인덱스는 그대로
    if cur <= len[sz - 1]:
        return dnc(cur, sz - 1)
    
    # 뒤쪽 구간이면 이전의 크기 + "moo.."의 크기를 더한 만큼 인덱스를 뺌
    elif cur > len[sz - 1] + sz + 3:
        return dnc(cur - len[sz - 1] - sz - 3, sz - 1)
    
    # 가운데 구간이고 첫번째 인덱스면 'm' 아니면 'o' 반환
    return 'm' if cur == len[sz - 1] + 1 else 'o'

n = int(input().strip())
len[0] = 3
for i in range(1, 55):
    len[i] = 2 * len[i - 1] + i + 3
    mx = i
    # 오버플로우 방지
    if len[i] > n:
        break

print(dnc(n, mx))

