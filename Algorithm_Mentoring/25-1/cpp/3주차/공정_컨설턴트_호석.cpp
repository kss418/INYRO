#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n, m, a[MAX];

bool decision(ll cur){
    // 최소 시간 출력
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    // cur개 만큼의 공정 라인 사용 가능
    for(int i = 1;i <= cur;i++) pq.push(0);

    ll mx = 0; // 공정 라인 사용 시간 최댓값
    for(int i = 1;i <= n;i++){
        // 제일 적은 공정 라인 사용 시간
        ll now = pq.top(); pq.pop();
        // 현재 제작 시간을 더함
        pq.push(now + a[i]);
        mx = max(mx, now + a[i]);
    }

    // 공정 라인 사용 시간 최댓값이 M보다 작으면
    // cur개의 라인으로 M시간 내에 제작 가능
    return mx <= m;
}

ll maximization(){
    ll lo = 1, hi = 2e5;
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
    cout << maximization();

    return 0;
}

