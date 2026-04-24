#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> reportInfo;
    map<string, int> reportCnt;
    
    vector<string>::iterator iter;
    
    for (string r: report) {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;
        
        iter = find(reportInfo[reporter].begin(), reportInfo[reporter].end(), reported);
        if (iter != reportInfo[reporter].end()) continue;
        
        reportInfo[reporter].push_back(reported);
        reportCnt[reported]++;
    }
    
    for (int i=0; i<id_list.size(); i++) {
        int cnt = 0;
        string reporter = id_list[i];
        
        for (int j=0; j<reportInfo[reporter].size(); j++) {
            if (reportCnt[reportInfo[reporter][j]] >= k) cnt++;
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}
