#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    int x_count[10] = {0};
    int y_count[10] = {0};
    
    for (char c : X) x_count[c - '0']++;
    for (char c : Y) y_count[c - '0']++;
    
    string answer = "";
    answer.reserve(min(X.size(), Y.size())); 

    for (int i = 9; i >= 0; i--) {
        int n = min(x_count[i], y_count[i]);
        for (int j = 0; j < n; j++) {
            answer.push_back(i + '0'); 
        }
    }
    
    if (answer.empty()) return "-1";
    if (answer[0] == '0') return "0";

    return answer;
}
