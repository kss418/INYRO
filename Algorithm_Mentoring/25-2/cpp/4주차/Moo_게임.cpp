#include <iostream>
using namespace std;
using ll = long long;

const ll MAX = 55;
const ll INF = 1e12;
ll n, len[MAX], mx;

char dnc(ll cur, ll sz){
    // Base Case
    if(!sz) return (cur == 1 ? 'm' : 'o');

    // 앞쪽 구간이면 인덱스는 그대로
    if(cur <= len[sz - 1]) return dnc(cur, sz - 1);

    // 뒤쪽 구간이면 이전의 크기 + "moo.."의 크기를 더한 만큼 인덱스를 뺌
    else if(cur > len[sz - 1] + sz + 3){
        return dnc(cur - len[sz - 1] - sz - 3, sz - 1);
    }

    // 가운데 구간이고 첫번째 인덱스면 'm' 반환 아니면 'o' 반환
    return (cur == len[sz - 1] + 1 ? 'm' : 'o');
}

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n; len[0] = 3;
    for(int i = 1;i < 55;i++){
        len[i] = 2 * len[i - 1] + i + 3; mx = i;
        // 오버플로우 방지
        if(len[i] > n) break;
    }

    cout << dnc(n, mx);
    return 0;
}

