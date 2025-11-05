#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n, l, result;
pair <ll, ll> a[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++){
        // first -> 끝점
        // second -> 시작점
        cin >> a[i].first >> a[i].second;
        // 시작점이 끝점보다 크면 스왑
        if(a[i].second > a[i].first) swap(a[i].first, a[i].second);
    }

    cin >> l;
    // 끝점을 기준으로 정렬
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        // 현재 시작점을 우선순위 큐에 넣음
        pq.push(a[i].second);
        // 우선순위 큐의 값과 현재 구간의 끝점의 차이가 
        // L보다 크면 값 삭제
        while(!pq.empty() && pq.top() < a[i].first - l) pq.pop();

        // 우선순위 큐의 크기 최댓값으로 정답 갱신
        result = max<ll>(result, pq.size());
    }

    cout << result;
    return 0;
}

