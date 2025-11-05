#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e12;
ll n, m, k, ind[MAX];
ll a[MAX], dp[MAX];
vector <ll> adj[MAX];
queue <ll> q;

void run(){
    cin >> n >> m;
    // 값 입력 및 초기화
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        dp[i] = ind[i] = 0;
        adj[i].clear();
    }

    // 간선 입력
    while(m--){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        ind[e]++;
    }
    cin >> k;

    for(int i = 1;i <= n;i++){
        if(!ind[i]) q.push(i);
    }
    
    while(!q.empty()){
        ll cur = q.front(); q.pop();
        // 현재 DP값에 현재 건물 짓는 데 걸리는 시간 추가
        dp[cur] += a[cur];
        for(auto& nxt : adj[cur]){
            // 다음 DP 값은 이전의 건물을 짓는 데 드는 
            // 시간 중 최댓값으로 갱신
            dp[nxt] = max(dp[nxt], dp[cur]);
            if(!--ind[nxt]) q.push(nxt);
        }
    }

    ll result = 0;
    cout << dp[k] << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    ll t; cin >> t;
    while(t--) run();

    return 0;
}

