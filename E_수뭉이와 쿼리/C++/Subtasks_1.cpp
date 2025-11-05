#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
string S; 

ll solve(ll l, ll r){
    ll ret = 0;

    // L 부터 R 까지 순회
    for(int i = l;i <= r;i++){
        if(S[i - 1] != 'S') continue;

        // 현재 s[i]가 'S' 이면
        for(int j = i + 1;j <= r;j++){
            if(S[j - 1] != 'M') continue;
            // i 이후의 'M'의 개수를 더함
            ret++;
        }
    }

    return ret;
}

void run(){
    ll M;
    cin >> S >> M;
    while(M--){
        ll L, R; cin >> L >> R;
        cout << solve(L, R) << "\n";
    }
}

int main(){
    fastio;
    ll t; cin >> t;
    while(t--) run();
    return 0;
}
