#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll INF = 1e9;
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
ll d[MAX][MAX], a[MAX][MAX], n, m;

class node{
public:
    ll y, x;
};
queue <node> q;

// 다음에 볼 배열의 인덱스가 범위 밖이거나 벽인지 판단
bool outrange(ll cy, ll cx){
    if(cy <= 0 || cx <= 0 || cy > n || cx > m) return 1;
    return a[cy][cx] == -1;
}

void bfs(){
    while(!q.empty()){
        auto [cy, cx] = q.front(); q.pop();
        for(int i = 0;i < 4;i++){
            // 다음에 볼 인덱스
            ll ny = cy + dy[i], nx = cx + dx[i];

            // 다음에 볼 인덱스가 범위 밖이거나 벽이면 건너 뜀
            if(outrange(ny, nx)) continue;
            // 이미 방문 했으면 건너 뜀
            if(d[ny][nx] != INF) continue;
            // 다음에 볼 인덱스의 최단거리 배열을
            // 현재 최단거리 배열 +1로 바꿈
            d[ny][nx] = d[cy][cx] + 1;
            q.push({ny, nx});
        }
    }
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> m >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            // 매우 큰 값으로 초기화
            // 거리 배열이 INF가 아니면 방문 한 배열
            d[i][j] = INF;

            // 현재 인덱스가 익은 토마토면
            if(a[i][j] == 1){
                // 거리 배열을 0으로 바꾸고 큐에 삽입
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    bfs();
    ll result = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            // 벽이면 건너 뜀
            if(a[i][j] == -1) continue;
            // 최단거리의 최댓값으로 갱신
            result = max(result, d[i][j]);
        }
    }

    // 모든 토마토가 익을 수 없으면 -1
    cout << (result == INF ? -1 : result);

    return 0;
}