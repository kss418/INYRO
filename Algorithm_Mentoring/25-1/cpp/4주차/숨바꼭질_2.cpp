#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n, m, d[MAX], cnt[MAX];
queue <ll> q;

void bfs(ll st){
    q.push(st); 
    d[st] = 0; cnt[st] = 1;

    while(!q.empty()){
        ll cur = q.front(); q.pop();
        for(auto& nxt : {cur + 1, cur - 1, 2 * cur}){
            // 다음 정점이 점 밖에 있으면 건너 뜀
            if(nxt < 0 || nxt >= MAX) continue;
            // 다음 정점이 방문하지 않은 정점이면
            if(d[nxt] == -1){
                // 큐에 삽입하고 거리 배열 +1
                q.push(nxt); 
                d[nxt] = d[cur] + 1;
            }
            
            // 다음 정점과의 거리가 최단거리이면
            // 현재 정점까지 가는 경우의 수를 더함
            if(d[nxt] == d[cur] + 1) cnt[nxt] += cnt[cur];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    // 방문 배열 초기화
    for(int i = 0;i < MAX;i++) d[i] = -1;
    bfs(n);

    cout << d[m] << "\n" << cnt[m];

    return 0;
}