#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

void run(){
    // 문자열로 입력 받음
    string s; cin >> s;
    ll sum = 0;

    // 각 자리의 합을 더함
    for(auto& i : s) sum += i - '0';

    // 6의 배수이려면 동시에 
    // 2의 배수이고 3의 배수여야 함

    // 2의 배수인 조건 -> 마지막 자리의 수가 짝수
    // 3의 배수인 조건 -> 모든 자리 수의 합이 3의 배수
    cout << (((s.back() - '0') % 2) == 0 && (sum % 3 == 0) ? "Yes" : "No") << "\n";
}

int main(){
    fastio;
    ll t; cin >> t;
    while(t--) run();
    return 0;
}
