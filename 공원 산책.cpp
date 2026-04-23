#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
	vector<int> answer;

	int start_row = 0;
	int start_col = 0;

	bool isbreak = false;

	for (int i = 0; i < park.size(); i++) {
		for (int j = 0; j < park[i].size(); j++) {
			if (park[i][j] == 'S') {
				start_row = i;
				start_col = j;
				isbreak = true;
				break;
			}
		}
		if (isbreak) break;
	}
for (int i = 0; i < routes.size(); i++) {
		const char *jump_char = &routes[i][2];
		int jump = atoi(jump_char);
		switch (routes[i][0])
		{
		case 'N':
			if (start_row - jump >= 0){
				bool flag = false;
				for (int j = 1; j <= jump; j++) {
					if (park[start_row - j][start_col] == 'X') {
						flag = true;
						break;
					}
				}
				if (!flag) {
					start_row -= jump;
				}
			}
			break;
			
		case 'S':
			if (start_row + jump < park.size()) {
				bool flag = false;
				for (int j = 1; j <= jump; j++) {
					if (park[start_row + j][start_col] == 'X') {
						flag = true;
						break;
					}
				}
				if (!flag) {
					start_row += jump;
				}
			}
			break;

		case 'W':
			if (start_col - jump >= 0) {
				bool flag = false;
				for (int j = 1; j <= jump; j++) {
					if (park[start_row][start_col-j] == 'X') {
						flag = true;
						break;
					}
				}
				if (!flag) {
					start_col -= jump;
				}
			}
			break;

		case 'E':
			if (start_col + jump < park[0].size()) {
				bool flag = false;
				for (int j = 1; j <= jump; j++) {
					if (park[start_row][start_col + j] == 'X') {
						flag = true;
						break;
					}
				}
				if (!flag) {
					start_col += jump;
				}
			}
			break;

		default:
			break;
		}
	}

	answer.push_back(start_row);
	answer.push_back(start_col);

	return answer;
}
