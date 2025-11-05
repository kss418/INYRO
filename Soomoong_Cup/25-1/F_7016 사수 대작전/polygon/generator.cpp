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

    cout << tc << endl;
    while(tc--){
        cout << n << endl;
        for(int i = 1;i <= n;i++){
            ll a = rnd.next(1ll, 2000ll);
            cout << a;
            if(i == n) break;
            cout << " ";
        }
        cout << endl;

        for(int i = 1;i <= n;i++){
            ll b = rnd.next(1ll, 2000ll);
            cout << b;
            if(i == n) break;
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}