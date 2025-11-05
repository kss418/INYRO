#include <iostream>
#include <vector>
using namespace std;
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

vector <char> st;
bool chk(){
    int sz = st.size();
    if(sz < 3) return 0;
    if(st[sz - 1] != 'B') return 0;
    if(st[sz - 2] != 'B') return 0;
    if(st[sz - 3] != 'A') return 0;

    return 1;
}

int main(){
    fastio;

    int t; cin >> t;
    while(t--){
        int n; string s;
        cin >> n >> s;
        st.clear(); // 스택 초기화

        for(int i = 0;i < n;i++){
            st.push_back(s[i]); 
            int cnt = 0; // 현재 연산 횟수

            while(chk()){ // 스택의 마지막 값이 ABB인지 판별
                for(int i = 0;i < 3;i++) st.pop_back(); // ABB 제거
                cnt++; st.push_back('B'); // ABB를 B로 변환 후 연산 횟수 1 증가
            }

            for(int j = 1;j <= cnt;j++) st.push_back('A'); // 연산 횟수 만큼 A 삽입
        }

        for(int i = 0;i < st.size();i++) cout << st[i];
        cout << "\n";
    }
}  
