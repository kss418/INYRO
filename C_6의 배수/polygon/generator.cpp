#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 50101;
string s;

int main(int argc, char* argv[]) {
    fastio;
    registerGen(argc, argv, 1);

    ll tc = stoll(argv[1]);
    ll n = stoll(argv[2]);

    cout << tc << endl;
    while(tc--){
        ll num = rnd.next(1, 9);
        s.push_back((char)(num + '0'));
        for(int i = 1;i < n;i++){
            ll num = rnd.next(0, 9);
            s.push_back((char)(num + '0'));
        }

        cout << s << endl;
        s.clear();
    }

    return 0;
}