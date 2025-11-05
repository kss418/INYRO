#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 505;
ll n, m, dp[MAX][MAX], a[MAX][MAX];
ll dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

bool outrange(ll cy, ll cx){
    return cx <= 0 || cy <= 0 || cx > m || cy > n;
}

ll solve(ll cy, ll cx){
    ll& ret = dp[cy][cx];
    if(ret != -1) return ret; ret = 0;
    // Base Case
    if(cy == 1 && cx == 1) return ret = 1;

    for(int i = 0;i < 4;i++){
        ll ny = cy + dy[i], nx = cx + dx[i];
        // 격자 밖이면 건너 뜀
        if(outrange(ny, nx)) continue;
        // 내리막 길이 아니면 건너 뜀
        if(a[ny][nx] <= a[cy][cx]) continue;
        ret += solve(ny, nx);
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }
    cout << solve(n, m);

    return 0;
}

