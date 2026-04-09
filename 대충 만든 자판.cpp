#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> charToPresses;
    
    for(int i = 0; i < keymap.size(); i++){
        for(int j = 0; j < keymap[i].size(); ++j){
            char c = keymap[i][j];
            if(charToPresses.find(c) == charToPresses.end() || charToPresses[c] > j + 1){
                charToPresses[c] = j + 1;
            }
        }
    }
    
    for(const string& target : targets){
        int totalPresses = 0;
        bool canType = true;
        for(char c : target){
            if(charToPresses.find(c) == charToPresses.end()){
                canType = false;
                break;
            } else{
                totalPresses += charToPresses[c];
            }
        }
        if(!canType){
            answer.push_back(-1);
        } else{
            answer.push_back(totalPresses);
        }
    }
    
    return answer;
}
