#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool visited[8] = { false, };
int max_dungeons = 0;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void dfs(int count, int current_k, int** dungeons, size_t dungeons_rows) {
    max_dungeons = MAX(max_dungeons, count);

    for (size_t i = 0; i < dungeons_rows; ++i) {
        if (!visited[i] && current_k >= dungeons[i][0]) {
            visited[i] = true; // 1.
            
            dfs(count + 1, current_k - dungeons[i][1], dungeons, dungeons_rows);
            
            visited[i] = false; 
        }
    }
}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    max_dungeons = 0;
    for (int i = 0; i < 8; ++i) {
        visited[i] = false;
    }

    dfs(0, k, dungeons, dungeons_rows);

    return max_dungeons;
}
