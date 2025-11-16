#include <iostream>
using namespace std;
bool v[1010];

void solve(){
    int n, result = 0; cin >> n;
    for(int i = 1;i < 1010;i++) v[i] = 0;
    
    for(int i = 1;i <= n;i++){
        int s, e, c; cin >> s >> e >> c;
        if(v[s]) continue;
        v[s] = 1; result++;
    }

    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();
    return 0;
}