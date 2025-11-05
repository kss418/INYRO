#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using pll = pair<ll, ll>;

const ll INF = 1e12;

// 다익스트라
class _dij{
public:
    class node{
    public:
        ll nxt, c, l;
    };

    vector <vector<node>> adj;
    vector <ll> dist;
    priority_queue <pll, vector<pll>, greater<pll>> pq;
    ll n = 0;

    _dij(){}
    _dij(ll n){
        this->n = n;
        adj.clear(); adj.resize(n + 1);
    }

    // 간선 추가
    void add(ll s, ll e, ll c, ll l){
        adj[s].push_back({e, c, l});
        adj[e].push_back({s, c, l});
    }

    // s -> e 최단거리 반환
    ll ret(ll s, ll e, ll t){
        dist.clear(); dist.resize(n + 1, INF);
        while(!pq.empty()) pq.pop();
        pq.push({t, s});

        while(!pq.empty()){
            auto [cd, cur] = pq.top(); pq.pop();
            if(dist[cur] <= cd) continue;
            dist[cur] = cd;

            for(auto&[nxt, co, ban] : adj[cur]){
                // 현재 최단거리가 막차 시간 이상이면 건너 뜀
                if(cd >= ban) continue;
                if(dist[nxt] <= cd + co) continue;
                pq.push({cd + co, nxt});
            }
        } 

        return dist[e];
    }
}; _dij dij;


ll t0, N, M;
bool decision(ll cur){
    // 출발 시간이 cur일 때 정점 N까지의 최단 거리
    ll ret = dij.ret(1, N, cur);

    // 이동 시간이 같으면 1 아니면 0 반환
    return ret <= t0 + cur;
}

// 매개 변수 탐색
ll maximization(){
    ll lo = 0, hi = 101010;
    while(lo < hi){
        ll mid = (lo + hi + 1) / 2;

        // mid 일 때 이동 시간이 같으면 lo -> mid로 변경
        if(decision(mid)) lo = mid;
        // mid 일 때 이동 시간이 다르면 hi -> mid - 1로 변경
        else hi = mid - 1;
    }
    return lo;
}

void run(){
    cin >> N >> M; dij = {N};
    while(M--){
        // 간선 입력
        ll s, e, c, l; cin >> s >> e >> c >> l;
        dij.add(s, e, c, l);
    }
    
    // 출발 시간이 0일 때의 최단 거리
    t0 = dij.ret(1, N, 0);

    // 출발 시간이 0일 때 정점 N에 도착하지 못하면 -1
    if(t0 >= INF) cout << -1 << "\n"; 
    else{
        // 매개변수 탐색으로 가장 처음으로 
        // 이동시간이 달라진 출발 시간을 구함
        cout << t0 << " " << maximization() << "\n";
    }
}

int main(){
    fastio;
    ll t; cin >> t;
    while(t--) run();
    return 0;
}
