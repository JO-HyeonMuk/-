#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;

    // 1. 예각: 0도보다 크고 90도보다 작은 경우
    if (0 < angle && angle < 90){
        answer = 1;
    }
    // 2. 직각: 정확히 90도인 경우
    else if(angle == 90){
        answer = 2;
    }
    // 3. 둔각: 90도보다 크고 180도보다 작은 경우
    else if(90 < angle && angle <180){
        answer = 3;
    }
    // 4. 평각: 위의 조건에 해당하지 않는 경우 (보통 문제 맥락상 180도인 경우)
    else {
        answer = 4;
    }
    
    return answer;
}
