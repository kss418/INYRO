#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

constexpr ll MAX = 20101;
string S; ll N, M;
ll pre[MAX];

// 누적합 계산
void init(){
    for(int i = 1;i <= N;i++){
        pre[i] = pre[i - 1];
        if(S[i - 1] == 'S') pre[i]++;
    }
}

// "SM" 쌍 계산
ll solve(ll l, ll r){
    ll ret = 0;
    for(int i = l;i <= r;i++){
        if(S[i - 1] == 'S') continue;
        // 현재 S[i]가 'M'이면
        // L ~ i 까지의 'S'의 개수를 더함
        ret += pre[i] - pre[l - 1];
    }
    return ret;
}

void run(){
    cin >> S >> M; N = S.size(); init();
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
