#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

constexpr ll INF = 1e12;
constexpr ll MAX = 30101;
ll N, A[MAX], B[MAX];
ll dp[MAX][101];

// DP 식 계산
ll solve(ll cur, ll mx){
    ll& ret = dp[cur][mx];
    if(ret != -1) return ret; ret = INF;
    if(!cur) return ret;
    
    // j == 0, 현재 서 있는 상태이므로
    // 전의 모든 DP에서 서 있을 때 드는 비용을 더한 값의 최솟값
    if(!mx) for(int i = 0;i <= 100;i++) ret = min(ret, solve(cur - 1, i) + B[cur]);
    else{
        // j == A[i], 처음으로 앉은 상태이므로
        // 전의 모든 DP에서 앉아 있을 때 드는 비용을 더한 값의 최솟값
        if(mx == A[cur]){
            for(int i = 0;i <= 100;i++) ret = min(ret, solve(cur - 1, i) + A[cur]);
        }

        // j != A[i] && j != 0, 이미 앉아 있는 상태이므로
        // 앉아 있는 상태의 드는 비용을 더함
        else ret = min(ret, solve(cur - 1, mx) + mx);
    }

    return ret;
}

void run(){
    // DP 값 초기화
    memset(dp, -1, sizeof(dp)); dp[0][0] = 0;

    cin >> N; 
    for(int i = 1;i <= N;i++) cin >> A[i];
    for(int i = 1;i <= N;i++) cin >> B[i];

    ll result = INF;
    for(int i = 0;i <= 100;i++) result = min(result, solve(N, i));
    cout << result << "\n";
}

int main(){
    fastio;
    ll t; cin >> t;
    while(t--) run();
    return 0;
}
