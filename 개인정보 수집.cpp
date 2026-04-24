#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

// 전역 변수 설정 (오늘 날짜 정보 및 약관 맵, 계산된 일수 저장)
int year, month, day, total;
map<char, int> t_map; // 약관 종류별 유효기간 저장 (A: 6개월 등)
vector<int> priv; // 각 개인정보의 만료일을 '일' 단위로 저장

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    // --- 1단계: 오늘 날짜를 '일' 단위로 변환 ---
    // 한 달을 28일로 가정하므로: (연도 * 12 * 28) + (월 * 28) + 일
    year = stoi(today.substr(0, 4)); 
    month = stoi(today.substr(5, 2)); 
    day = stoi(today.substr(8, 2));
    total = year * 12 * 28 + (month - 1) * 28 + day;

    // --- 2단계: 약관 정보 파싱 ---
    // stringstream을 사용해 "A 6" 같은 문자열에서 약관 종류와 기간을 분리해 맵에 저장
    for(int i = 0; i < terms.size(); i++){
        stringstream ss(terms[i]);
        char alpha; int month;
        ss >> alpha >> month;
        t_map[alpha] = month;
    }

    // --- 3단계: 개인정보별 만료일 계산 ---
    for(int i = 0; i < privacies.size(); i++){
        int y = stoi(privacies[i].substr(0, 4)); 
        int m = stoi(privacies[i].substr(5, 2)); 
        int d = stoi(privacies[i].substr(8, 2));
        char a = privacies[i].back(); // 약관 종류 (문자열의 마지막 글자)

        // 해당 날짜를 '일'로 변환 + (약관 개월수 * 28) - 1일 = 만료일
        // -1을 하는 이유는 수집일로부터 유효기간이 끝나는 '당일'까지는 보관 가능하기 때문
        int tmp = y * 12 * 28 + (m - 1) * 28 + d + (t_map[a] * 28 - 1);
        
        priv.push_back(tmp);
    }

    // --- 4단계: 오늘 날짜와 비교하여 파기 대상 선별 ---
    for(int i = 0; i < priv.size(); i++){

        // 만료일(priv[i])이 오늘(total)보다 작다면 이미 기간이 지난 것
        if(priv[i] < total){
            answer.push_back(i + 1); // 문제에서 번호는 1번부터 시작하므로 i+1
        }
    }
    
    
    return answer;
}
