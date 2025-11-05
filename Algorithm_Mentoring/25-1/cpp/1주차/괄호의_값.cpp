#include <iostream>
#include <stack>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;


stack <char> st;
bool chk(string& s){
    // 올바른 괄호열이면 1 아니면 0 반환
    for(int i = 0;i < s.size();i++){
        // 여는 괄호면 스택에 추가
        if(s[i] == '(' || s[i] == '[') st.push(s[i]); 
        else{
            // 매칭할 여는 괄호가 없으면 틀린 괄호열
            if(st.empty()) return 0;

            // 매칭할 여는 괄호가 다른 종류의 괄호면 틀린 괄호열
            if(s[i] == ')' && st.top() == '[') return 0;
            else if(s[i] == ']' && st.top() == '(') return 0;

            // 여는 괄호랑 매칭 했으므로 여는 괄호를 스택에서 제거
            st.pop();
        }
    }
    
    // 매칭되지 않은 괄호가 있으면 틀린 괄호열
    if(st.size()) return 0;
    
    // 끝까지 다 순회했는데 틀린 괄호열이 아니면
    // 올바른 괄호열
    return 1;
}

int result[31];
int main(){
    fastio;
    string s; cin >> s;
    if(!chk(s)){ // 틀린 괄호열이면 0 출력
        cout << 0; return 0;
    }

    int cnt = 0; // 현재 깊이
    for(int i = 0;i < s.size();i++){
        // 여는 괄호면
        if(s[i] == '(' || s[i] == '[') cnt++; // 깊이 증가

        // 닫는 괄호면
        else if(s[i] == ')'){
            cnt--; // 갚이 감소
            // 이전 값에 2를 곱해서 더함
            // 0 이면 1로 취급
            result[cnt] += 2 * max(result[cnt + 1], 1); 
            result[cnt + 1] = 0; // 이전 값 초기화
        }
        else{
            cnt--; // 깊이 감소
            // 이전 값에 3을 곱해서 더함
            // 0 이면 1로 취급
            result[cnt] += 3 * max(result[cnt + 1], 1);
            result[cnt + 1] = 0; // 이전 값 초기화
        }
    }

    // 정답은 인덱스 0에 있음
    cout << result[0]; 
    return 0;
}
