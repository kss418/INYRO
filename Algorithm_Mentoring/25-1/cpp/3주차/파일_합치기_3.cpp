#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010101;
ll n, a[MAX];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    // 최소 우선순위 큐
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    // 먼저 모든 값을 우선순위 큐에 넣음
    for(int i = 1;i <= n;i++) pq.push(a[i]);

    ll result = 0;
    // 우선순위 큐의 크기가 1이 될 때 까지 반복
    while(pq.size() > 1){
        // 제일 작은 수
        ll fi = pq.top(); pq.pop();
        // 두 번째로 작은 수
        ll se = pq.top(); pq.pop();

        // 합쳐서 우선순위 큐에 다시 넣음
        pq.push(fi + se);
        // 정답에 추가
        result += fi + se;
    }

    cout << result << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}

