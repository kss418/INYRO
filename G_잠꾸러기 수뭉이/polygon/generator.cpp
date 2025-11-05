#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long; using pll = pair<ll, ll>;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
constexpr ll MAX = 50101;

class Hash{
public:
    size_t operator()(const pll& p) const {
        return (size_t)p.first * MAX + (size_t)p.second;
    }
};

class node{
public:
    ll s, e, c, l;
};

int main(int argc, char* argv[]) {
    fastio;
    registerGen(argc, argv, 1);

    ll tc = stoll(argv[1]);
    ll n = stoll(argv[2]);
    ll m = stoll(argv[3]);
    ll max_cost = stoll(argv[4]);
    ll max_using = stoll(argv[5]);

    cout << tc << endl;
    while(tc--){
        vector <node> arr;
        unordered_set <pll, Hash> v;
        while(arr.size() < m){
            ll s = rnd.next(1ll, n);
            ll e = rnd.next(1ll, n);

            if(s == e) continue;
            if(s > e) swap(s, e);
            if(v.count({s, e})) continue;

            ll c = rnd.next(1ll, max_cost);
            ll l = rnd.next(1ll, max_using);

            v.insert({s, e});
            arr.push_back({s, e, c, l});
        }

        cout << n << " " << m << endl;
        for(auto& [s, e, c, l] : arr){
            cout << s << " " << e << " " << c << " " << l << endl;
        }
    }

    return 0;
}