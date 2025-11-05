#include <bits/stdc++.h>
using namespace std; using ll = long long;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

void run(){
    string s; cin >> s; 

    ll result = s.size();
    for(int i = 0;i < s.size();i++){
        // 인접한 두 문자가 같으면
        // 항상 길이를 1로 줄일 수 있음
        if(s[i] == s[i + 1]) result = 1;
    }
    
    cout << result << "\n";
}

int main(){
    fastio;
    ll t; cin >> t;
    while(t--) run();
    return 0;
}
