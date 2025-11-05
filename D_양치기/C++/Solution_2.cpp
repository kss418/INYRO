#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

constexpr ll MAX = 101010;
pair <ll, ll> a[MAX];
stack <ll> st;

int main(){
    fastio;
    ll N; cin >> N;
    for(int i = 1;i <= N;i++) cin >> a[i].first >> a[i].second;
    // 위치 순서대로 정렬
    sort(a + 1, a + N + 1);

    for(int i = 1;i <= N;i++){
        // 스택의 양의 속도가 현재 양의 속도보다 빠르면
        // 스택에서 제거
        while(!st.empty() && st.top() > a[i].second){
            st.pop();
        }

        // 스택에 삽입
        st.push(a[i].second);
    }

    cout << st.size();
    return 0;
}
