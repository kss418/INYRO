#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

constexpr ll MAX = 30101;
ll N, A[MAX], B[MAX];

void run(){
    cin >> N; ll result = 1e12;
    for(int i = 1;i <= N;i++) cin >> A[i];
    for(int i = 1;i <= N;i++) cin >> B[i];

    // 브루트포스
    // 각 비트가 1이면 앉기, 0이면 서 있기
    for(int i = 0;i < (1ll << N);i++){
        ll mn = 1e12, now = 0;
        for(int j = 0;j < N;j++){
            // j번째 정류장에서 앉아있다면 이전까지의 A 중 최솟값을 더함
            if(i & (1ll << j)){
                mn = min(mn, A[j + 1]);
                now += mn;
            }

            // 서 있을 때는 mn 초기화 후 B 비용을 더함
            else{
                mn = 1e12;
                now += B[j + 1];
            }
        }

        // 최솟값이 갱신
        result = min(result, now);
    }

    cout << result << "\n";
}

int main(){
    fastio;
    ll t; cin >> t;
    while(t--) run();
    return 0;
}
