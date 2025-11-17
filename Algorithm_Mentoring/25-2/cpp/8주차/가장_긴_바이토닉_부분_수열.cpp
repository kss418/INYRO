#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 1010;
ll dp[MAX][2], a[MAX], n;

ll solve(ll cur, ll cnt){
    ll& ret = dp[cur][cnt];
    if(ret != -1) return ret; ret = 1;

    // 감소하는 상태
    if(cnt) for(int i = 1;i < cur;i++){
        // 이전 값이 현재 값보다 작으면 건너 뜀
        if(a[i] <= a[cur]) continue;
        ret = max(ret, solve(i, 0) + 1);
        ret = max(ret, solve(i, 1) + 1);
    }
    // 증가하는 상태
    else for(int i = 1;i < cur;i++){
        // 이전 값이 현재 값보다 크면 건너 뜀
        if(a[i] >= a[cur]) continue;
        ret = max(ret, solve(i, 0) + 1);
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < MAX;i++){
        for(int j = 0;j <= 1;j++) dp[i][j] = -1;
    }

    ll result = 0;
    for(int i = 1;i <= n;i++){
        // DP[i][0], DP[i][1] 중 최댓값이 정답
        result = max(result, max(solve(i, 0), solve(i, 1)));
    }
    cout << result;
    return 0;
}

