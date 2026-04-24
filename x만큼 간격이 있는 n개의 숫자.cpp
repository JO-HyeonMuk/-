#include <string>
#include <vector>

using namespace std;

// x: 시작 숫자이자 증가하는 간격, n: 담을 숫자의 개수
vector<long long> solution(int x, int n) {
    vector<long long> answer; // 결과를 저장할 벡터 (큰 숫자를 담기 위해 long long 타입)

    // start 변수에 초기값 x를 할당 (현재 숫자를 추적하는 역할)
    // ※ 주의: x가 int 범위를 넘어서 계속 더해질 경우 오버플로우 위험이 있어 
    // 실제 서비스 코드라면 long long start = x; 로 선언하는 것이 더 안전합니다
    int start = x;

    // n번 반복하며 숫자를 생성
    for(int i = 0; i < n; i++)
    {
        // 현재 숫자를 결과 리스트에 추가
        answer.push_back(start);

        // 다음 숫자를 만들기 위해 x만큼 더함 (등차수열의 원리)
        start += x;
    }
    
    return answer; // 생성된 숫자 리스트 반환
}
