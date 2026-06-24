#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping)
{
    int answer = 0, cake;
    unordered_map <int,int> base, cmp;
    for(auto c : topping) base[c]++;
    cake = base.size();
    for(auto c : topping)
    {
        cmp[c]++; base[c]--;
        if (base[c] == 0 ) cake--;
        if (cake == cmp.size()) answer++;
    }
    return answer;
}
