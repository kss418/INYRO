#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()

constexpr ll MAX = 101010;
pair <ll, ll> a[MAX];
stack <ll> st;

int main(){
    fastio;
    ll N; cin >> N;
    for(int i = 1;i <= N;i++) cin >> a[i].first >> a[i].second;
    // 위치 순서대로 정렬
    sort(a + 1, a + N + 1);
    
    ll slow = 1e12, result = 0;
    for(int i = N;i >= 1;i--){
        // 현재 양의 속도가 가장 느린 양의 속도보다 느리면
        // 정답에 1 추가
        if(a[i].second <= slow) result++;

        // 가장 느린 양의 속도 갱신
        slow = min(slow, a[i].second);
    }

    cout << result;
    return 0;
}
