#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1010];
class node{
public:
    int s, e, c;
    bool operator < (const node& ot) const{
        if(e != ot.e) return e < ot.e;
        return s < ot.s;
    }
}; vector <node> arr;

void solve(){
    int n, result = 0; 
    cin >> n; arr.clear();
    for(int i = 0;i < 1010;i++) dp[i] = 0;
    
    for(int i = 1;i <= n;i++){
        int s, e, c; cin >> s >> e >> c;
        arr.push_back({s, e, c});
    }

    sort(arr.begin(), arr.end());
    for(auto& [s, e, c] : arr){
        for(int i = 1;i <= s;i++){
            dp[e] = max(dp[e], dp[i] + c);
            result = max(result, dp[e]);
        }
    }

    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();
    return 0;
}