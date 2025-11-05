#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 201010;
ll a[MAX], n, m;

bool decision(ll cur){
    // cnt -> 설치한 공유기 개수
    // last -> 마지막으로 설치한 공유기 위치
    ll cnt = 0, last = -1e12; // last는 음의 무한대로 초기화
    for(int i = 1;i <= n;i++){
        // 마지막으로 설치한 공유기의 위치와
        // 현재 위치의 차이가 K보다 작다면 건너 뜀
        if(a[i] - last < cur) continue;
        last = a[i]; cnt++;
    }

    // 설치한 공유기 개수가 M 이상이면
    // 공유기 거리의 차이의 최솟값을 K로 만들 수 있음
    return cnt >= m;
}

ll maximization(){
    // 최솟값은 1, 최댓값은 1e9
    // 실수 오차 있을 수 있으니 넉넉하게 2e9로 잡음
    ll lo = 1, hi = 2e9;
    while(lo < hi){
        ll mid = (lo + hi + 1) / 2; // 올림 값 사용
        if(decision(mid)) lo = mid;
        else hi = mid - 1;
    }

    return lo;
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    cout << maximization();

    return 0;
}





