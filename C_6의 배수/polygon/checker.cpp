#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAX = 1ll << 62;

int main(int argc, char* argv[]) {
    setName("checker");
    registerTestlibCmd(argc, argv);
    
    ll cnt = 0;
    while(!ans.seekEof() && !ouf.seekEof()){
        cnt++;

        string ret = ans.readToken("(Yes|No)", "ret");
        string out = ouf.readToken("(Yes|No)", "out");
        if(ret != out){
            quitf(_wa, "1");
        }
    }

    ll extans = 0, extouf = 0;
    while(!ouf.seekEof()){
        ouf.readToken("(Yes|No)", "out");
        extouf++;
    }

    while(!ans.seekEof()){
        ans.readToken("(Yes|No)", "ret");
        extans++;
    }

    if(extans){
        quitf(_wa, "less Output");
    }
    else if(extouf){
        quitf(_wa, "Exceed Ouput");
    }
    quitf(_ok, "1");

    return 0;
}