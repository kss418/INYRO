#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 200000;

int main(int argc, char* argv[]) {
    fastio;
    registerValidation(argc, argv);

    ll tc = inf.readLong(1ll, 10ll, "tc");
    inf.readEoln();

    while(tc--){
        ll n = inf.readLong();
        inf.readEoln();

        for(int i = 1;i <= n;i++){
            ll s = inf.readLong(1ll, MAX, "s");
            inf.readSpace();
            ll e = inf.readLong(s + 1, MAX, "e");
            inf.readSpace();
            ll c = inf.readLong(1ll, MAX, "c"); 
            inf.readEoln();
        }
    }

    inf.readEof();
    return 0;
}