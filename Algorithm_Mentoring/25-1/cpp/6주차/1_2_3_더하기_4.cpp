#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 10101;
ll dp[MAX][4];

ll solve(ll cur, ll mx){
    if(cur < 0) return 0;
    ll& ret = dp[cur][mx];
    if(ret != -1) return ret; ret = 0;
    if(!cur) return ret = (mx == 1);
    
    for(int i = 1;i <= mx;i++) ret += solve(cur - mx, i);
    return ret;
}

void run(){
    ll n; cin >> n;
    ll result = 0;
    for(int i = 1;i <= 3;i++) result += solve(n, i);
    cout << result << "\n";
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    for(int i = 0;i < MAX;i++){
        for(int j = 0;j < 4;j++) dp[i][j] = -1;
    }

    ll t; cin >> t;
    while(t--) run();

    return 0;
}

