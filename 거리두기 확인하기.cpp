#include <string>
#include <vector>
#include <cstring>

using namespace std;

int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
bool visited[5][5];
bool check;

void dfs(vector<string> v, int x, int y, int cnt){
    visited[x][y]=true;
    cnt++;
    
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && nx<5 && ny>=0 && ny<5 && !visited[nx][ny]){
            if(v[nx][ny]=='O' && cnt<2) dfs(v, nx, ny, cnt);
            else if(v[nx][ny]=='P') check=false;
        }
    }
    
    return;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i<5; i++){
        check=true;
        memset(visited, false, sizeof(visited));
        
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(places[i][j][k]=='P' && !visited[j][k]){
                    dfs(places[i], j, k, 0);
                    
                    if(!check) break;
                }
            }
            
            if(!check) break;
        }
        
        answer.push_back(check);
    }
    
    return answer;
}
