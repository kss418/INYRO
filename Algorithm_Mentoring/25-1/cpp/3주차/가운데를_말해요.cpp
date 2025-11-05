#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const ll MAX = 1010101;
ll n, a[MAX];
priority_queue <ll> pq1;
priority_queue <ll, vector<ll>, greater<ll>> pq2;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++){
        ll x; cin >> x;
        // 홀수 번째에는 최대 우선순위 큐에 삽입
        if(i % 2) pq1.push(x);
        // 짝수 번째에는 최소 우선순위 큐에 삽입
        else pq2.push(x);

        // 최대 우선순위 큐의 값이 최소 우선순위 큐의 값보다 크면
        if(!pq2.empty() && pq1.top() > pq2.top()){
            ll t1 = pq1.top();
            ll t2 = pq2.top();
            // 서로 스왑해 줌
            pq1.pop(); pq2.pop();
            pq1.push(t2); pq2.push(t1);
        }

        // 최대 우선순위 큐의 최댓값이 중간 값
        cout << pq1.top() << "\n";
    }
}

