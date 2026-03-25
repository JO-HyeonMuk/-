#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    static const vector<vector<int>> patterns = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };

    vector<int> scores(patterns.size(), 0);

    for (int i = 0; i < answers.size(); ++i) {
        for (int p = 0; p < patterns.size(); ++p) {
            if (patterns[p][i % patterns[p].size()] == answers[i]) {
                scores[p]++;
            }
        }
    }

    int max_score = *max_element(scores.begin(), scores.end());

    for (int i = 0; i < scores.size(); ++i) {
        if (scores[i] == max_score) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
