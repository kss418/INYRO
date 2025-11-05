#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX = 101;
const ll INF = 1e12;

ll n, m, ind[MAX], dp[MAX][MAX];
vector <ll> basic;
queue <ll> q;
vector <pll> adj[MAX];

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    while(m--){
        ll e, s, c; cin >> e >> s >> c;
        adj[s].push_back({e, c});
        ind[e]++;
    }

    for(int i = 1;i <= n;i++){
        if(ind[i]) continue;
        // ind[i] == 0 이면
        // 큐에 넣고 기본 부품으로 지정
        q.push(i);
        basic.push_back(i);

        // 기본 부품을 만드는데는 자기 자신 1개가 필요함
        dp[i][i] = 1; 
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(auto& [nxt, co] : adj[cur]){
            // dp[nxt]를 만드는데 드는 부품은 dp[cur] * co 만큼 추가로 들음
            // 각 부품 1 ~ N 까지 반복해야 함
            for(int i = 1;i <= n;i++) dp[nxt][i] += co * dp[cur][i];
            if(!--ind[nxt]) q.push(nxt);
        }
    }

    for(auto& i : basic){
        // 기본 부품에 대해서만 개수 출력
        cout << i << " " << dp[n][i] << "\n";
    }

    return 0;
}

