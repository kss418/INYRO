#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 1010;
ll n, dp[MAX][2];
ll diff[3] = {-1, -3, -4};

ll solve(ll cur, ll turn){
    ll& ret = dp[cur][turn]; 
    if(ret != -1) return ret; ret = turn ^ 1;

    for(int i = 0;i < 3;i++){
        ll nxt = cur + diff[i];
        if(nxt < 0) break; // 돌은 음수가 될 수 없음
        if(turn) ret = max(ret, solve(nxt, turn ^ 1));
        else ret = min(ret, solve(nxt, turn ^ 1));
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio
    
    cin >> n;
    for(int i = 0;i < MAX;i++){
        for(int j = 0;j < 2;j++) dp[i][j] = -1;
    }

    dp[0][0] = 0; dp[0][1] = 1;
    cout << (solve(n, 0) ? "CY" : "SK");

    return 0;
}

