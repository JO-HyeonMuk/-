#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, idx = 0, max = *max_element(priorities.begin(), priorities.end());
    
    while(answer < priorities.size()) {
        if(max == priorities[idx]) {
            answer++;
            if(idx == location) return answer;
            priorities[idx] = 0;
            max = *max_element(priorities.begin(), priorities.end());
        }
        idx++;
        if(idx == priorities.size()) idx = 0;
    }
}
