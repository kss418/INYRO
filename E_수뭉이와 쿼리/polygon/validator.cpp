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
        string s = inf.readToken();
        ensuref(s.size() <= 20000, "s size > 20000");
        inf.readSpace();
        ll m = inf.readLong(1ll, (ll)s.size(), "m");
        inf.readEoln();
        
        for(int i = 1;i <= m;i++){
            ll l = inf.readLong(1ll, (ll)s.size() - 1, "l");
            inf.readSpace();
            ll r = inf.readLong(l, (ll)s.size(), "r");
            inf.readEoln();
        }
    }

    inf.readEof();


    return 0;
}