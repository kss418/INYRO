#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 20101;
ll n, m, a[MAX];
pair <ll, ll> b[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i].first >> b[i].second;
    // 정렬
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    // idx -> 현재 보는 구간의 인덱스
    ll idx = 1, result = 0; 
    for(int i = 1;i <= n;i++){
        // 현재 구간을 끝까지 안봤고
        // 구간의 시작점이 배열의 값 이하면
        while(idx <= m && b[idx].first <= a[i]){
            // 우선순위 큐에 끝점 삽입
            pq.push(b[idx].second);
            idx++; // 보는 구간의 인덱스 1 증가
        }

        // 우선순위 큐의 값이 현재 배열의 값보다 작으면
        // 매칭 할 수 없으므로 삭제
        while(!pq.empty() && pq.top() < a[i]) pq.pop();
        // 우선순위 큐가 비어있지 않으면
        if(!pq.empty()){
            // 매칭 가능
            result++; pq.pop();
        }
    }

    cout << result;

    return 0;
}

