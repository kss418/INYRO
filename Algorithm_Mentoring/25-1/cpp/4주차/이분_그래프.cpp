#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;

const ll MAX = 20101;
vector <ll> a[MAX];
ll v[MAX], result, n, m;

void dfs(ll cur, ll num){
    // 현재 정점의 번호 설정
    v[cur] = num;
    
    for(auto& nxt : a[cur]){
        // 다음 정점을 방문 했으면
        if(v[nxt] != -1){
            // 배치할 번호와 이미 배치 된 번호가 다르면 NO
            if(v[nxt] != num ^ 1) result = 0;
            continue;
        }

        // 번호를 바꿔서 탐색
        dfs(nxt, num ^ 1); 
    }
}

void add(int s, int e){
    // 양방향 간선 추가
    a[s].push_back(e);
    a[e].push_back(s);
}

void solve(){
    cin >> n >> m;

    result = 1;
    for(int i = 1;i <= n;i++) {
        // 간선 리스트와 방문 배열 초기화
        a[i].clear(); v[i] = -1;
    }

    while(m--){
        // 간선 추가
        ll s, e; cin >> s >> e;
        add(s, e);
    }

    for(int i = 1;i <= n;i++){
        // 방문을 했으면 넘어 감
        if(v[i] != -1) continue;
        dfs(i, 0);
    }

    cout << (result ? "YES" : "NO") << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    ll t; cin >> t;
    while(t--) solve();

    return 0;
}