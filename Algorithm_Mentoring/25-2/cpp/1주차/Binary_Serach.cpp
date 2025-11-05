#include <iostream>
using namespace std;
int a[7] = { 1, 4, 6, 11, 14, 16, 22};

int binary_search(int x){
    int lo = 0, hi = 6; // A의 크기가 7이므로 hi = 6(7 - 1)
    int ret = -1; // A에 x가 존재하지 않을 경우 -1 반환

    while(lo <= hi){ // 시작점이 끝점보다 커지면 종료
        int mid = (hi + lo) / 2; // 중간값
        if(a[mid] == x){ // 현재 값이 탐색하고 있는 값이면
            ret = mid; break; // 정답은 mid, while문 종료
        }
        // 현재 값이 탐색하고 있는 값보다 크면 
        if(a[mid] > x) hi = mid - 1; // mid 이상의 인덱스에는 x가 없음
        else lo = mid + 1; // 아니면 mid 이하의 인덱스에는 x가 없음
    }
    
    return ret;
}


int main(){
    cout << binary_search(4) << "\n"; // 1
    cout << binary_search(14) << "\n"; // 4
    cout << binary_search(15) << "\n"; // -1
 
    return 0;
}

