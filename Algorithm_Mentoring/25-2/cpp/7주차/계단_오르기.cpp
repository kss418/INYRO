#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 303;
const ll INF = 1e9;
ll n, a[MAX], dp[MAX][2];

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    // Base Case
    dp[1][0] = a[1];
    dp[2][0] = a[2];
    dp[2][1] = a[1] + a[2];
    
    for(int i = 3;i <= n;i++){
        // 전의 계단을 밟았으면 전의 계단에서 점화식 전이
		dp[i][1] = dp[i - 1][0] + a[i];

        // 전의 계단을 밟지 않았으면 2칸 전의 계단에서 점화식 전이
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
    }

    // 둘 중 큰 값이 정답
    cout << max(dp[n][0], dp[n][1]);

    return 0;
}

