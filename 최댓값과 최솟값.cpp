#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> v;
    string str;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ')
        {
            v.push_back(stoi(str));
            str="";
        }
        else
            str+=s[i];
    }
    v.push_back(stoi(str));
    
    int MaxNum=v[0],MinNum=v[0];
    for(int i=1; i<v.size();i++)
    {
        MaxNum=max(MaxNum,v[i]);
        MinNum=min(MinNum,v[i]);
    }
    string answer = "";
    answer=to_string(MinNum)+" "+to_string(MaxNum);
    return answer;
}
