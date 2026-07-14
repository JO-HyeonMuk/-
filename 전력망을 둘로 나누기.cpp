#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

vector<int> g[101];
bool visited[101];

int bfs(int start, int n) {
    queue<int> q;
    int result = 0;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result++;
        
        for (int i = 0; i < g[current].size(); i++) {
            if(visited[g[current][i]] == true) continue;
            q.push(g[current][i]);
            visited[g[current][i]] = true;
        }
    }
    
    return abs(result * 2 - n);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1234567890;
    
    for (int i = 0; i < wires.size(); i++) {
        for (int j = 0; j < wires.size(); j++) {
            if (j == i) continue;
            g[wires[j][0]].push_back(wires[j][1]);
            g[wires[j][1]].push_back(wires[j][0]);
        }
        answer = min(bfs(wires[i][0], n), answer);
        memset(visited, false, sizeof(bool) * 101);
        
        for (int j = 0; j < 101; j++) {
            g[j].clear();
        }
    }
    
    return answer;
}
