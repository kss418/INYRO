#include <iostream>
#include <stack>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

stack <pair <int, int>> st;
int a[501010];
int main(){
    fastio;
    int n; cin >> n;
    long long result = 0;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++){
        // 이전의 값이 현재 값보다 작을 때
        while(!st.empty() && st.top().first < a[i]){ 
            // 정답에 이전의 값의 개수만큼 더함
            // 작은 값들은 더 이상 다음 값들을 만날 수 없으므로
            // 스택에서 빼줌
            result += st.top().second; st.pop();
        }

        // 스택이 비었거나 이전의 값이 현재 값이랑 다르면 한 개 추가
        if(st.empty() || st.top().first != a[i]) st.push({a[i], 1});
        else{
            // 이전의 값이 현재 값이랑 같으면
            // 이전 값에 1 추가해서 넣어 줌
            int num = st.top().second + 1;
            st.pop(); st.push({a[i], num});

            // 같은 값들끼리는 서로 볼 수 있으므로 정답에 더함
            result += num - 1;
        }

        // 스택의 값이 2개 이상이면 정답에 1 추가
        if(st.size() >= 2) result++;
    }

    cout << result;
    return 0;
}


