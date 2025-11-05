#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 10101;
ll n, m, result;
pair <ll, ll> a[MAX];
priority_queue <ll> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i].first >> a[i].second;
    ll en, fuel; cin >> en >> fuel;
    a[n + 1].first = en; // 마을도 포함
    sort(a + 1, a + n + 2); // 거리가 가까운 순으로 정렬
    
    for(int i = 1;i <= n + 1;i++){
        // 현재 주유소의 거리가 갈 수 있는 거리보다 멀면
        while(a[i].first > fuel){
            // 비축해둔 연료가 없으면
            // 마을까지 갈 수 없으므로 -1
            if(pq.empty()){ cout << -1; return 0; }

            // 가장 많은 연료부터 소모
            ll now = pq.top(); pq.pop();
            fuel += now; result++;
        }

        // 연료를 비축해둠
        pq.push(a[i].second);
    }

    cout << result;

    return 0;
}

