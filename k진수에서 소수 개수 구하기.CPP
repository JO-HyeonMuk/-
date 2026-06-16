#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define LL long long

using namespace std;
int K;
string S, T;
int Answer;

string transitDec(int X) {
    string Result = "";
    
    while (X > 0) {
        Result += ((char)((X % K) + 48));
        X /= K;
    };
    
    reverse(Result.begin(), Result.end());
    
    return Result;
}

bool isPrime(LL X) {
    if (X <= 1) return false;
    for (LL i = 2; i <= sqrt(X); i++) {
        if (X % i == 0) {
            return false;
        }
    }
    
    return true;
}

int solution(int n, int k) {
    K = k;
    S = transitDec(n);
    for (int i = 0; i < (int)S.length(); i++) {
        if ((int)T.length() == 0) {
            T += S[i];
            continue;
        }
        
        if (S[i] != '0') {
            T += S[i];
            continue;
        }
        
        if (isPrime(stoll(T))) {
            Answer++;
        }
        T = "";
    }
    if (isPrime(stoll(T))) {
        Answer++;
    }
    
    return Answer;
}
