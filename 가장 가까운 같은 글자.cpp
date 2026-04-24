#include <string>
#include <vector>
#include <map> // 각 문자의 마지막 위치를 저장하기 위해 map 사용

using namespace std;

vector<int> solution(string s) {
    vector<int> answer; // 결과값(상대적 거리)을 담을 벡터
    map<char, int> last_pos; // key: 문자(char), value: 마지막으로 등장한 인덱스(int)
    
    for( int i = 0; i < s.length(); i++)
    {
        // --- 1단계: 현재 문자(s[i])가 이전에 나온 적이 있는지 확인 ---
        // last_pos.find(s[i])가 end()를 가리키면 한 번도 등장하지 않았다는 뜻입니다.
        if(last_pos.find(s[i]) == last_pos.end()){
            answer.push_back(-1); // 처음 등장하면 -1을 저장
        }
        else{
            
            // --- 2단계: 이전에 등장했다면 거리 계산 ---
            // (현재 인덱스 i) - (마지막으로 저장된 인덱스 last_pos[s[i]])
            answer.push_back(i - last_pos[s[i]]);
        }

        // --- 3단계: 현재 문자의 위치 정보를 최신화 ---
        // 다음번에 이 문자가 또 나오면 현재 위치(i)를 기준으로 거리를 재야 하므로 업데이트합니다.
        last_pos[s[i]] = i;
    }
    return answer;
}
