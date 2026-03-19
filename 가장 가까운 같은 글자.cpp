#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> last_pos;
    
    for( int i = 0; i < s.length(); i++)
    {
        if(last_pos.find(s[i]) == last_pos.end()){
            answer.push_back(-1);
        }else{
            answer.push_back(i - last_pos[s[i]]);
        }
        last_pos[s[i]] = i;
    }
    return answer;
}
