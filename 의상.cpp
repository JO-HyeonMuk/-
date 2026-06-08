#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<pair<string, int>> clothe;
    
    for(int i = 0; i < clothes.size(); ++i) {
        auto it = find_if(clothe.begin(), clothe.end(), [&](const pair<string, int>& p) {
            return p.first == clothes[i][1];
        });
        if(it == clothe.end()) {
            clothe.push_back(make_pair(clothes[i][1], 1));
        }
        else it->second++;
    }
    for(int i = 0; i < clothe.size(); ++i) {
        answer *= (clothe[i].second + 1);
    }
    return answer - 1;
}
