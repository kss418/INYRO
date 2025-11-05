#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 101;
ll n, m, dp[MAX][101010];
ll w[MAX], c[MAX], result;

ll solve(ll cur, ll num){
    ll& ret = dp[cur][num];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret;

    // 물건을 고르지 않음
    ret = max(ret, solve(cur - 1, num));

    // 물건을 고름
    if(num >= w[cur]) ret = max(ret, solve(cur - 1, num - w[cur]) + c[cur]);

    // 정확히 무게의 합이 num이 아닌 경우도 세야 함
    if(num) ret = max(ret, solve(cur, num - 1));

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> w[i] >> c[i];
    for(int i = 0;i <= n;i++){
        for(int j = 0;j < 101010;j++) dp[i][j] = -1;
    }

    cout << solve(n, m);
    return 0;
}

