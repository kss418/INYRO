#include <iostream>
#include <vector>
using namespace std;

vector <int> a[11];
bool v[11];

void dfs(int cur){
    // 방문한 정점으로 표시
    v[cur] = 1;
    cout << cur << "\n";
    
    for(auto& nxt : a[cur]){
        // 다음 정점이 방문한 정점이면 넘어 감
        if(v[nxt]) continue;
        dfs(nxt); 
    }
}

void add(int s, int e){
    // 양방향 간선 추가
    a[s].push_back(e);
    a[e].push_back(s);
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    add(1, 2); add(2, 4); add(2, 5); 
    add(1, 3); add(3, 6); add(6, 7);
    dfs(1);

    return 0;
}

