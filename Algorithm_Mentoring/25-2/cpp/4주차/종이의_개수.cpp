#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 3010;
const ll INF = 1e12;
ll n, a[MAX][MAX], cnt[3];

void dnc(ll cy, ll cx, ll sz){
    bool flag = 1; // 모든 종이가 같으면 1 아니면 0
    ll num = a[cy][cx]; // 시작 종이의 숫자
    for(int i = cy;i < cy + sz;i++){
        for(int j = cx;j < cx + sz;j++){
            // 시작 종이와 현재 종이가 다르면 flag = 0
            if(a[i][j] != num) flag = 0;
        }
    }

    // 모든 종이가 같으면 시작 종이의 개수를 1 증가
    // 및 재귀 함수 종료
    if(flag){
        cnt[num + 1]++; return;
    }

    // 다음 종이의 크기
    ll nsz = sz / 3;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            // 분할
            dnc(cy + i * nsz, cx + j * nsz, nsz);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }

    dnc(0, 0, n);
    for(int i = 0;i < 3;i++) cout << cnt[i] << "\n";
    return 0;
}

