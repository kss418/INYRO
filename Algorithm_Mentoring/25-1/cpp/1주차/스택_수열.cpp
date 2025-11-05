#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector <char> result;
stack <int> st;
int main(){
    int n; cin >> n;
    int use = 1; // 스택에 삽입 할 수
    for(int i = 1;i <= n;i++){
        int x; cin >> x; // 현재 출력해야 하는 수
        while(use <= x){ // X가 삽입이 안되었으면
            st.push(use); use++; // 스택에 수 삽입
            result.push_back('+'); // 정답에 + 추가
        }
        
        // 스택이 비었거나 스택의 값이 X가 아니면
        if(st.empty() || st.top() != x){ 
            cout << "NO"; 
            return 0;
        }

        st.pop(); 
        result.push_back('-'); // 정답에 - 추가
    }

    for(int i = 0;i < result.size();i++) cout << result[i] << '\n';


    return 0; 
}

