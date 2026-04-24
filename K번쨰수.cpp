#include <string>
#include <vector>
#include <algorithm> // sort 함수를 사용하기 위해 필요

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer; // 최종 결과값들을 담을 벡터

    // 주어진 명령어(commands)의 개수만큼 반복 실행
    for(int i = 0 ; i < commands.size();i++){
        // 명령의 구성: [시작 index, 끝 index, 찾을 번째수]
        // 예: [2, 5, 3] -> 2번째부터 5번째까지 자르고 3번째 숫자 찾기
        
        vector<int> clone; // 원본 배열에서 자른 부분을 저장할 임시 벡터


        // --- 1단계: 배열 자르기 ---
        // 문제에서의 인덱스는 1부터 시작하므로, 실제 배열 인덱스(0부터 시작)에 맞추기 위해 -1을 해줍니다.
        // commands[i][0]-1 부터 commands[i][1]-1 까지 반복하며 복사
        for(int j = commands[i][0]-1; j <= commands[i][1]-1; j++){
            clone.push_back(array[j]);
        }

        // --- 2단계: 정렬하기 ---
        // 잘라낸 배열(clone)을 오름차순으로 정렬합니다.
        sort(clone.begin(),clone.end());

        // --- 3단계: K번째 수 추출하기 ---
        // 정렬된 배열에서 K번째(commands[i][2]) 숫자를 선택합니다.
        // 이 또한 인덱스 조정을 위해 -1을 해준 뒤 answer에 담습니다.
        answer.push_back(clone[commands[i][2]-1]);
    }
    
    return answer; // 모든 명령에 대한 결과 리스트 반환
}
