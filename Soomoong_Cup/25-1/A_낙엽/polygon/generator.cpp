#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 50101;

int main(int argc, char* argv[]) {
    fastio;
    registerGen(argc, argv, 1);

    ll n = stoll(argv[1]);
    ll m = rnd.next(1ll, n);
    ll k = rnd.next(1ll, n);
    cout << n << " " << m << " " << k << endl;
    for(int i = 1;i <= n;i++){
        ll a = rnd.next(1ll, k);
        cout << a;
        if(i == n) break;
        cout << " ";
    }
    cout << endl;

    return 0;
}