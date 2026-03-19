#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    int check;
    for(int i=food.size()-1; i>0; i--){
        check = food[i]/2;
        while(check){    
            answer = to_string(i) + answer + to_string(i);
            check--;
        }
    }
    return answer;
}
