#include <iostream>

int minimization(){
    // 정답의 범위는 1 ~ N
    int lo = 1, hi = N;
    while(lo < hi){
        int mid = (lo + hi) / 2; // 중간값
        // 결정 문제의 답이 1 이면 
        // 정답은 [lo, mid]에 존재
        if(decision(mid)) hi = mid;
        
        // 결정 문제의 답이 0 이면
        // 정답은 [mid + 1, hi]에 존재
        else lo = mid + 1;
    }

    return lo;
}

int maximization(){
    // 정답의 범위는 1 ~ N
    long long lo = 1, hi = N;
    while(lo < hi){
        long long mid = (lo + hi + 1) / 2; // 중간값
        // 결정 문제의 답이 1 이면 
        // 정답은 [mid, hi]에 존재
        if(decision(mid)) lo = mid;
        
        // 결정 문제의 답이 0 이면
        // 정답은 [lo, mid - 1]에 존재
        else hi = mid - 1;
    }

    return lo;
}
