#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <int, int>> arr;

void solve(){
    int n, result = 0; 
    cin >> n; arr.clear();
    
    for(int i = 1;i <= n;i++){
        int s, e, c; cin >> s >> e >> c;
        arr.push_back({e, s});
    }

    sort(arr.begin(), arr.end());
    int last = -1;
    for(auto& [e, s] : arr){
        if(s < last) continue;
        last = e; result++;
    }
    
    cout << result << "\n";
}

int main(){
    int t; cin >> t;
    for(int i = 1;i <= t;i++) solve();
    return 0;
}