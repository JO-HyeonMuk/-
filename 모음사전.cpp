#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string word) {
    int answer = 0;
    map<char, int> alpha{
        make_pair('A', 0),
        make_pair('E', 1),
        make_pair('I', 2),
        make_pair('O', 3),
        make_pair('U', 4)
    };
    vector<int> num{781, 156, 31, 6, 1};
    
    for(int i = 0; i < word.size(); ++i) {
        answer += alpha[word[i]] * num[i] + 1;
    }
    return answer;
}
