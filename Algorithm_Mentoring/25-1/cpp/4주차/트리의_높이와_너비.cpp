#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 10101;
const ll INF = 1e9;
ll n, m, l[MAX], r[MAX], idx[MAX];
bool root[MAX];
ll cnt, dep[MAX], mn[MAX], mx[MAX];

void dfs(ll cur, ll dep = 1){
    // 왼쪽 자식이 있으면 DFS
    if(l[cur] != -1) dfs(l[cur], dep + 1);

    // 왼쪽 자식 탐색이 끝났으면
    // 현재 정점에 번호 부여
    ll num = ++cnt;
    mn[dep] = min(mn[dep], num);
    mx[dep] = max(mx[dep], num);

    // 오른쪽 자식이 있으면 DFS
    if(r[cur] != -1) dfs(r[cur], dep + 1);
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    // 루트 값을 찾아야 함
    // min 값 INF로 초기화
    for(int i = 1;i <= n;i++) root[i] = 1, mn[i] = INF;
    for(int i = 1;i <= n;i++){
        cin >> idx[i] >> l[idx[i]] >> r[idx[i]];

        // 누군가의 자식 정점이면 루트 노드가 아님
        if(l[idx[i]] != -1) root[l[idx[i]]] = 0;
        if(r[idx[i]] != -1) root[r[idx[i]]] = 0;
    }

    for(int i = 1;i <= n;i++){
        // 루트 노드가 아니면 건너 뜀
        if(!root[i]) continue;
        dfs(i);
    }

    ll diff = 0, result = 0;
    for(int i = 1;i <= n;i++){
        // 현재 깊이의 너비가 원래 너비보다 크면
        if(mx[i] - mn[i] + 1 > diff){
            // 값 갱신
            result = i;
            diff = mx[i] - mn[i] + 1;
        }
    }

    cout << result << " " << diff;

    return 0;
}