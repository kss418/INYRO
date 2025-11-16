#include <iostream>
using namespace std;
int cache[101];

int main(){
    // 캐시 배열 초기화
    for(int i = 0;i <= 100;i++) cache[i] = -1;
    cache[1] = cache[2] = 1;
    for(int i = 3;i <= 45;i++) cache[i] = cache[i - 1] + cache[i - 2];

    cout << cache[45];
}

