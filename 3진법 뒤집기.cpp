#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sqr = 1;
    vector<int> a;
    while(n)
    {
        a.push_back(n%3);
        n/=3;
    }
    for(int i=0; i < a.size(); i++)
    {
        answer += a[a.size()-i-1]*(sqr);
        sqr*=3;
    }
    
    return answer;
}
