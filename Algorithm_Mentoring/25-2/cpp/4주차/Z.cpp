#include <iostream>
using namespace std;
using ll = long long;
ll n, m, k;

ll dnc(ll cur, ll cy, ll cx){
    // Base Case
    if(cur == 1) return 2 * cy + cx;

    // 현재 정사각형의 길이의 절반
    ll len = (1ll << (cur - 1));

    // 왼쪽 dx = 0, 오른쪽 dx = 1
    // 위쪽 dy = 0, 아래쪽 dy = 1
    ll dy = cy / len, dx = cx / len;

    // 현재 정사각형의 1/4의 크기에 위치를 곱해서 더함
    return dnc(cur - 1, cy % len, cx % len) + (2 * dy + dx) * len * len;
}

int main(){
    cin >> n >> m >> k;
    cout << dnc(n, m, k);
    return 0;
}