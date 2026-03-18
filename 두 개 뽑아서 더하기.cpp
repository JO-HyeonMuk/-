#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sum_set;
    
    for(int i = 0; i < numbers.size() - 1; ++i)
    {
        for(int j = i + 1; j < numbers.size(); ++j)
        {
            sum_set.insert(numbers[i] + numbers[j]);
        }
    }
    
    return vector<int>(sum_set.begin(), sum_set.end());
}
