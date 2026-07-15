#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    map<pair<int,pair<int,int>>, bool> m;
    bool able[51];
    fill(able, able+51, false);
    
    vector<pair<int, int>> v[51];
    for(int i=0; i<road.size(); i++) {
        v[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    
    stack<pair<int,int>> s;
    s.push(make_pair(1, 0));
    able[1]=true;
    
    while(!s.empty()) {
        int cur = s.top().first;
        int cost = s.top().second; 
        s.pop();
        
        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second;
            if(m.find(make_pair(cur,make_pair(next, cost+nextCost)))==m.end()
               && cost+nextCost<=K 
               && next!=1) {
                s.push(make_pair(next, cost+nextCost));
                m.insert({make_pair(cur, make_pair(next, cost+nextCost)), true});
                able[next]=true;
            }
        }
    }
    
    for(int i=1; i<=N; i++) {
        if(able[i])
            answer++;
    }

    return answer;
}
