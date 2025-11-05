#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
ll A, B, N, mx;

int main(){
    fastio;

    cin >> N >> A >> B;
    for(int i = 1;i <= N;i++){
        ll x; cin >> x;
        // 가장 큰 값만 저장
        mx = max(mx, x);
    }

    ll result = 0, sum = 0;
    while(A--){
        // 오늘 밤에 낙엽이 쌓였을 때
        // B가 넘으면 낮에 낙엽을 치워줘야 함
        if(sum + mx > B){
            // 정답에 1 추가
            result++;
            sum = 0;
        }

        // 밤에 낙엽이 쌓임
        sum += mx;
    }

    cout << result;
    return 0;
}
