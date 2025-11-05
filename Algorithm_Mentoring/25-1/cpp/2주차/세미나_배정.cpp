#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll n, m, a[MAX], num[MAX];

bool decision(ll cur){
    // 현재 사용중인 세미나의 시작날의 최댓값
    ll last = 0;
    for(int i = 1;i <= n;i++){
        // K개의 세미나실을 아직 다 안썼다면
        // 시작날을 max(a[i] - m + 1, 1)로 지정
        if(i <= cur) last = max(a[i] - m + 1, 1ll);

        // K개의 세미나실을 다 썼다면
        // K의 인덱스 전의 세미나의 시작날의 M을 더함
        else last = max({a[i] - m + 1, num[i - cur] + m, 1ll});

        // 세미나의 시작날 저장
        num[i] = last;

        // 세미나의 시작날이 지정한 날보다 늦으면
        // K개의 세미나실로 세미나를 진행 할 수 없음
        if(a[i] - num[i] < 0) return 0;
    }
    
    // 아니면 K개의 세미나실로 진행 할 수 있음
    return 1;
}

ll minimization(){
    // 구간의 최댓값은 2e5
    ll lo = 1, hi = 201010;
    while(lo < hi){
        ll mid = (lo + hi) / 2;
        if(decision(mid)) hi = mid;
        else lo = mid + 1;
    }

    return lo;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    
    cout << minimization();

    return 0;
}





