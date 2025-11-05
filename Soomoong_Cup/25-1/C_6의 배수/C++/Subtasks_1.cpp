#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

void run(){
    ll n; cin >> n;
    cout << (n % 6 ? "No" : "Yes") << "\n";
}

int main(){
    fastio;
    ll t; cin >> t;
    while(t--) run();
    return 0;
}

