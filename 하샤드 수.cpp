#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int y = x;
    while(y){
        sum += y%10;
        y /= 10;
    }
    if(x % sum == 0){
        answer = true;
    }else{
        answer = false;
    }
        
    return answer;
}
