#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 101;
const ll MOD = 1e9;
ll n, dp[MAX][10], result;

ll solve(ll cur, ll num){
    // 수가 음수거나 한 자리 수가 아니면 0 반환
    if(num > 9 || num < 0) return 0;
    ll& ret = dp[cur][num];
    if(ret != -1) return ret; ret = 0;

    // 0으로 시작하는 계단 수는 계단 수가 아님
    if(cur == 1) return ret = num ? 1 : 0;

    // 이전의 수와 현재 수가 한개 차이가 나야 함
    ret += solve(cur - 1, num + 1) % MOD;
    ret += solve(cur - 1, num - 1) % MOD;

    return ret %= MOD;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio
    
    ll n; cin >> n;
    for(int i = 0;i < MAX;i++){
        for(int j = 0;j <= 9;j++) dp[i][j] = -1;
    }

    // 0 ~ 9의 합이 정답
    for(int i = 0;i <= 9;i++){
        result += solve(n, i);
        result %= MOD;
    }

    cout << result;
    return 0;
}

