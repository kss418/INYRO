#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 50000;

int main(int argc, char* argv[]) {
    fastio;
    registerValidation(argc, argv);

    ll tc = inf.readLong(1ll, 10ll, "tc");
    inf.readEoln();


    while(tc--){
        ll n = inf.readLong(1ll, MAX, "n");
        inf.readSpace();
        ll m = inf.readLong(1ll, n * (n - 1) / 2, "m");
        inf.readEoln();
        
        for(int i = 1;i <= m;i++){
            ll s = inf.readLong(1ll, n, "s");
            inf.readSpace();
            ll e = inf.readLong(1ll, n, "e");
            inf.readSpace();
            ll c = inf.readLong(1ll, 100000, "c");
            inf.readSpace();
            ll l = inf.readLong(1ll, 1000000, "l");
            inf.readEoln();
        }
    }

    inf.readEof();


    return 0;
}