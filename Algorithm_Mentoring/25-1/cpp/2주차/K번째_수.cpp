#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll n, m;

bool decision(ll cur){
    // cur 보다 작은 수의 개수
    ll cnt = 0;
    for(int i = 1;i <= n;i++){
        // i번째 열의 cur 보다 작은 수의 개수를 더함
        cnt += min(cur / i, n);
    }
    
    return cnt >= m;
}

ll minimization(){
    // 범위의 최댓값은 1e10
    ll lo = 1, hi = 2e10;
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
    cout << minimization();

    return 0;
}





