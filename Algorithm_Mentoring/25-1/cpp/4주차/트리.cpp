#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MAX = 55;
vector <ll> a[MAX];
ll n, p[MAX], m, result, root;

void dfs(ll cur){
    // 현재 노드가 삭제된 노드면 return
    if(cur == m) return;
    for(auto& nxt : a[cur]) dfs(nxt);

    // 현재 노드의 자손이 없거나
    // 자손이 1개고 자손이 삭제된 노드면 정답 +1
    if(a[cur].empty() || (a[cur].size() == 1 && a[cur][0] == m)) result++;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> p[i];
        // 부모가 -1이면 루트 노드
        if(p[i] == -1) root = i;
        // 아니면 간선 추가
        else a[p[i]].push_back(i);
    }
    cin >> m;

    dfs(root);
    cout << result;


    return 0;
}

