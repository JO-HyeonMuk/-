#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    
    for (int i=0; i<10; i++) {
        m[discount[i]]++;
    }
    
    for (int i=0; i<discount.size()-9; i++) {
        bool wantSignup = true;
        
        for (int j=0; j<want.size(); j++) {
            if (m[want[j]] != number[j]) {
                wantSignup = false;
                break;
            }
        }
        
        if (wantSignup) {
            answer++;
        }
        
        m[discount[i]]--;
        if (i < discount.size()-10) m[discount[i+10]]++;
    }
    
    return answer;
}
