#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll MAX = 10101;
ll n, m, result;
bool v[MAX];
vector <pll> adj[MAX];

class node{
public:
    ll s, e, c;
    // pq를 위한 > 연산자 오버로딩
    // 혹은 tuple 사용해서 간선이 앞으로 오게 하면 됨
    bool operator > (const node& ot) const{
        return c > ot.c;
    }
};
priority_queue <node, vector<node>, greater<node>> pq;

int main(){
    cin >> n >> m;
    while(m--){
        ll s, e, c; cin >> s >> e >> c;
        adj[s].push_back({e, c});
        adj[e].push_back({s, c});
    }

    // 시작 정점과 연결된 간선을 pq에 삽입
    for(auto& [e, c] : adj[1]) pq.push({1, e, c});
    v[1] = 1; // 시작 정점 방문 처리
    
    while(!pq.empty()){
        auto[s, e, c] = pq.top(); pq.pop();
        // 다음 정점을 방문 했으면 -> 같은 집합이면
        // 건너 뜀
        if(v[e] == 1) continue;

        // 정답에 비용 추가 및 방문 처리
        result += c; v[e] = 1;
        
        for(auto& [nxt, co] : adj[e]){
            // 이미 방문한 정점이면 건너 뜀
            if(v[nxt]) continue;

            // pq에 간선 삽입
            pq.push({e, nxt, co});
        }
    }

    cout << result;
    return 0;
}