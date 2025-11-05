#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 50101;

int main(int argc, char* argv[]) {
    fastio;
    registerGen(argc, argv, 1);

    ll tc = stoll(argv[1]);
    ll n = stoll(argv[2]);
    ll m = stoll(argv[3]);

    cout << tc << endl;
    while(tc--){
        string result = "";
        for(int i = 1;i <= n;i++){
            char c = rnd.next(0, 1) == 0 ? 'S' : 'M';
            result += c;
        }

        cout << result << " " << m << endl;
        for(int i = 1;i <= m;i++){
            ll l = rnd.next(1ll, n - 1);
            ll r = rnd.next(l + 1, n);
            cout << l << " " << r << endl;
        }
    }

    return 0;
}