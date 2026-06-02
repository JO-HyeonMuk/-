#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    answer.reserve(right - left + 1);
    
    for (long long i = left; i <= right; ++i) {
        long long row = i / n;
        long long col = i % n;

        answer.push_back(static_cast<int>(max(row, col) + 1));
    }
    
    return answer;
}
