#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX = 1010;
ll n, m, k, result, a[MAX];
bool v[MAX];
vector <pll> adj[MAX];

class node{
public:
    ll s, e, c;
    bool operator > (const node& ot) const{
        return c > ot.c;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++) cin >> a[i];
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    for(int i = 1;i <= k;i++){
        v[a[i]] = 1;
        for(auto& [e, c] : adj[a[i]]) pq.push({a[i], e, c});
    }
    
    while(!pq.empty()){
        auto[s, e, c] = pq.top(); pq.pop();
        if(v[e] == 1) continue;
        result += c; v[e] = 1;
    
        for(auto& [nxt, co] : adj[e]){
            if(v[nxt]) continue;
            pq.push({e, nxt, co});
        }
    }

    cout << result;
    return 0;
}