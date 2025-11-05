#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

constexpr ll MAX = 20101;
string S; ll N, M;
ll s_pre[MAX], sm_pre[MAX], m_pre[MAX];

// 누적 합 계산
void init(){
    for(int i = 1;i <= N;i++){
        s_pre[i] = s_pre[i - 1];
        if(S[i - 1] == 'S') s_pre[i]++;
    }

    for(int i = 1;i <= N;i++){
        m_pre[i] = m_pre[i - 1];
        sm_pre[i] = sm_pre[i - 1];
        if(S[i - 1] == 'M'){
            // "SM" 쌍의 개수는 현재 S[i]가 'M' 일때 
            // 이전의 'S'의 개수를 모두 더해준 값
            sm_pre[i] += s_pre[i];
            m_pre[i]++;
        }
    }
}

// "SM" 쌍 계산
ll solve(ll l, ll r){
    // L 이전의 "SM" 쌍의 개수는
    // L 이전의 'S' 개수와 L ~ R 사이의 'M' 개수를 곱해준 값

    // L ~ R 의 "SM" 쌍의 개수에서 L 이전의 "SM" 쌍의 개수를 빼줘야 함
    return sm_pre[r] - sm_pre[l - 1] - s_pre[l - 1] * (m_pre[r] - m_pre[l - 1]);
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
