#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[50101];
vector <pair<int, int>> adj[50101];

void solve(){
    int n, result = 0; cin >> n;
    for(int i = 0;i < 50101;i++){
        dp[i] = 0; adj[i].clear();
    }
    
    for(int i = 1;i <= n;i++){
        int s, e, c; cin >> s >> e >> c;
        adj[e].push_back({s, c});
    }

    for(int i = 1;i < 50101;i++){
        dp[i] = max(dp[i], dp[i - 1]);
        for(auto& [pre, co] : adj[i]){
            dp[i] = max(dp[i], dp[pre] + co);
        }

        result = max(result, dp[i]);
    }

    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();
    return 0;
}