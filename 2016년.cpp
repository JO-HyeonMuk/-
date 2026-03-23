#include <string>
#include <vector>

using namespace std;
string days[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
int month[] = { 31,29,31,30,31,30,31,31,30,31,30 };
string solution(int a, int b) {
    int sum = 4;
    for (int i = 0; i < a - 1; ++i)
    {
        sum += month[i];
    }
    return days[(sum + b) % 7];

}
