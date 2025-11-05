a = [1, 4, 6, 11, 14, 16, 22]

def binary_search(x):
    lo = 0
    hi = 6 # A의 크기가 7이므로 hi = 6(7 - 1)
    ret = -1 # A에 x가 존재하지 않을 경우 -1 반환

    while lo <= hi: # 시작점이 끝점보다 커지면 종료
        mid = (lo + hi) // 2 # 중간값
        if a[mid] == x: # 현재 값이 탐색하고 있는 값이면
            ret = mid # 정답은 mid
            break # while문 종료

        if a[mid] > x: # 현재 값이 탐색하고 있는 값보다 크면
            hi = mid - 1 # mid 이상의 인덱스에는 x가 없음
        else: # 현재 값이 탐색하고 있는 값보다 작으면
            lo = mid + 1 # mid 이하의 인덱스에는 x가 없음

    return ret

print(binary_search(4)) # 1
print(binary_search(14)) # 4
print(binary_search(15)) # -1

