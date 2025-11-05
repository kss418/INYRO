#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 7010;
ll n, m, k;
bool a[MAX][MAX];

void dnc(ll cur, ll cy, ll cx){
    // Base Case
    if(cur == 1){
        a[cy][cx] = 1;
        return;
    }

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            // 가운데면 건너 뜀
            if(i == 1 && j == 1) continue;
            // 분할 후 정사각형 크기
            ll nxt = cur / 3;

            // 분할
            dnc(nxt, cy + i * nxt, cx + j * nxt);
        }
    }
}

int main(){
    cin >> n; dnc(n, 0, 0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cout << (a[i][j] ? '*' : ' ');
        cout << "\n";
    }

    return 0;
}