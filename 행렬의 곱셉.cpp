#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    for (int row = 0; row < answer.size(); row++)
    {
        for (int col = 0; col < answer[0].size(); col++)
        {
            for (int i = 0; i < arr1[0].size(); i++)
            {
                answer[row][col] += arr1[row][i] * arr2[i][col];
            }
        }
    }
    return answer;
}
