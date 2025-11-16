#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 1010;
ll n, a[MAX], dp[MAX];

ll solve(ll cur){
    ll& ret = dp[cur];
    if(ret != -1) return ret; ret = 0;

    for(int i = 0;i < cur;i++){
        // 이전의 값이 크거나 같으면 증가하는 부분 수열이 아님
        if(a[i] >= a[cur]) continue;

        // 이전의 수열 길이에 +1
        ret = max(ret, solve(i) + 1);
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio
    
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < MAX;i++) dp[i] = -1;

    ll result = 0; dp[0] = 0;
    //1 ~ n의 DP값 중 최댓값이 정답
    for(int i = 1;i <= n;i++) result = max(result, solve(i));
    cout << result;

    return 0;
}

