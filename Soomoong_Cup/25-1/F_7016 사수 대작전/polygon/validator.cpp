#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 50101;
ll a[MAX], b[MAX];

int main(int argc, char* argv[]) {
    fastio;
    registerValidation(argc, argv);

    ll tc = inf.readLong(1ll, 10ll, "tc");
    inf.readEoln();

    while(tc--){
        ll n = inf.readLong(1ll, 10000ll, "n");
        inf.readEoln();

        for(int i = 1;i <= n;i++){
            a[i] = inf.readLong(1ll, 5000ll, "a");
            if(i == n) break;
            inf.readSpace();
        }
        inf.readEoln();

        for(int i = 1;i <= n;i++){
            b[i] = inf.readLong(1ll, 5000ll, "b");
            if(i == n) break;
            inf.readSpace();
        }
        inf.readEoln();
    }

    inf.readEof();


    return 0;
}