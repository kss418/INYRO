#include <iostream>
using namespace std;
int n, m, a[1010101];

bool decision(long long cur){
    long long cnt = 0; // 만들 수 있는 랜선의 개수
    for(int i = 1;i <= n;i++){
        // 랜선의 길이를 cur 만큼 자를 때
        // a[i] / cur 만큼 랜선이 나옴
        cnt += a[i] / cur; 
    }

    // 만들 수 있는 랜선의 개수가 M 이상이면 1 아니면 0 반환
    return cnt >= m;
}

int maximization(){
    // 정답의 범위는 1 ~ 2^31 - 1
    long long lo = 1, hi = (1 << 31) - 1;
    while(lo < hi){
        long long mid = (lo + hi + 1) / 2; // 중간값
        // 결정 문제의 답이 1 이면 
        // 정답은 [mid, hi]에 존재
        if(decision(mid)) lo = mid;
        
        // 결정 문제의 답이 0 이면
        // 정답은 [lo, mid - 1]에 존재
        else hi = mid - 1;
    }

    return lo;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cout << maximization(); // 최댓값 출력

    return 0;
}

