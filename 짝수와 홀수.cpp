#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string answer = "";
    
    answer = num & 1 ? "Odd" : "Even";
    
    return answer;
}
