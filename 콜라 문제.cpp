#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int count = 0;

    while( n >= a){
        answer += b*(n/a);
        
        count = n%a;
        n=b*(n/a) + count;
    }
    return answer;
}
