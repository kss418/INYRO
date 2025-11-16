#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 200000;

int main(int argc, char* argv[]) {
    fastio;
    registerGen(argc, argv, 1);

    ll tc = stoll(argv[1]);
    ll n = stoll(argv[2]);
    ll mx = stoll(argv[3]);
    ll c = stoll(argv[4]);
    bool f = stoll(argv[5]);

    cout << tc << endl;
    while(tc--){
        ll now = rnd.next(1ll, n);
        cout << now << endl;
        for(int i = 1;i <= now;i++){
            ll s = rnd.next(1ll, mx - 1);
            ll co = rnd.next(1ll, c);
            ll e = (f ? s + 1 : rnd.next(s + 1, mx));
            cout << s << " " << e << " " << co << endl;
        }
    }

    return 0;
}