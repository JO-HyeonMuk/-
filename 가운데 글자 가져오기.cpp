#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    // --- 1단계: 문자열의 길이가 짝수인 경우 처리 ---
    // 예: "abcde" (길이 5) -> 홀수 / "qwer" (길이 4) -> 짝수
    if(s.length()%2 ==0){
        
        // 길이가 짝수라면 가운데 두 글자 중 앞의 글자를 먼저 추가합니다.
        // 예: "qwer"에서 길이는 4, 4/2 - 1 = index 1 (즉, 'w')
        answer+=s[(s.length()/2)-1];
    }
    
    // --- 2단계: 공통 처리 (홀수/짝수 모두 포함) ---
    // 홀수일 때는 정확히 정중앙 글자가 되고,
    // 짝수일 때는 가운데 두 글자 중 뒤의 글자가 됩니다.
    // 예: "abcde"에서 5/2 = index 2 (즉, 'c')
    // 예: "qwer"에서 4/2 = index 2 (즉, 'e')
    answer+=s[(s.length()/2)];
    return answer;
}
