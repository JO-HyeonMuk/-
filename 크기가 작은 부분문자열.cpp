#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i = 0 ; i < t.size() - p.size() + 1; i++){
        string s = t.substr(i, p.size());

		if (p >= s){
            answer++;   
        }
    }
    return answer;
}
