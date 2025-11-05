#include <iostream>
#include <queue>
using namespace std;

vector <int> a[11];
bool v[11];

void bfs(int st){
    queue <int> q;
    // 큐에 시작점 추가 및 방문 처리
    q.push(st); v[st] = 1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << "\n";
        for(auto& nxt : a[cur]){
            // 방문한 정점이면 넘어 감
            if(v[nxt]) continue;
            // 큐에 다음 정점 삽입 및 방문 처리
            v[nxt] = 1;
            q.push(nxt);
        }
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
    bfs(1);

    return 0;
}

