#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 1010;
const ll MOD = 10007;
ll n, dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    // 현재 값이 이미 계산되었으면 반환
    if(ret != -1) return ret; ret = 0;
    // 점화식은 f(n - 1) + f(n - 2)
    ret += solve(cur - 1) + solve(cur - 2);

    return ret %= MOD; 
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    // 캐시 배열 초기화
    for(int i = 0;i < MAX;i++) dp[i] = -1;
    // Base Case 설정
    dp[1] = 1; dp[2] = 2;

    cout << solve(n);

    return 0;
}

