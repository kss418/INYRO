#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 50000;

int main(int argc, char* argv[]) {
    fastio;
    registerValidation(argc, argv);

    ll tc = inf.readLong(1ll, 1000ll, "tc");
    inf.readEoln();

    while(tc--){
        string s = inf.readWord("[0-9]+", "s");
        inf.readEoln();
    }
    inf.readEof();


    return 0;
}