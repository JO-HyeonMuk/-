#include <string>
#include <vector>

using namespace std;

// 요일 이름을 저장한 배열 (0: SUN ~ 6: SAT)
string days[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

// 각 달의 일수를 저장한 배열 (1월~11월까지 정의됨)
// ※ 2016년은 윤년이므로 2월이 29일까지 있습니다.
int month[] = { 31,29,31,30,31,30,31,31,30,31,30 };
string solution(int a, int b) {
    // sum의 초기값 4의 의미: 
    // 2016년 1월 1일이 금요일(FRI)이기 때문에, 
    // (sum + b) % 7 연산 시 1월 1일이 5(FRI)가 나오도록 맞춘 보정값입니다
    int sum = 4;

    // 1월부터 (a-1)월까지의 모든 일수를 더합니다.
    // 예: a가 3이라면 1월(month[0]), 2월(month[1])의 일수를 합산
    for (int i = 0; i < a - 1; ++i)
    {
        sum += month[i];
    }

    // (지난 달까지의 총 일수 + 이번 달의 날짜 b)를 7로 나눈 나머지를 구합니다.
    // 그 결과값을 이용해 days 배열에서 해당 요일을 찾아 반환합니다.
    return days[(sum + b) % 7];

}
