#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[5] = {4, 1, 2, 5, 3};
    sort(a, a + 5);

    for(int i = 0;i < 5;i++) cout << a[i] << " ";
}

