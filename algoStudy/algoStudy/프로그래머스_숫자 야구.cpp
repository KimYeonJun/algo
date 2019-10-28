#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	vector<int> number_list;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (i == j)
				continue;
			for (int k = 1; k < 10; k++) {
				if (j == k || i == k)
					continue;
				int tmp = i * 100 + j * 10 + k;
				number_list.push_back(tmp);
			}
		}
	}
	for (int i = 0; i < baseball.size(); i++) {
		for (int j = 0; j < number_list.size(); j++) {
			string b_str = to_string(baseball[i][0]);
			string n_str = to_string(number_list[j]);
			int s_cnt = 0;
			int b_cnt = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (b_str[k] == n_str[l]) {
						if (k == l) {
							s_cnt++;
						}
						else {
							b_cnt++;
						}
					}
				}
			}
			if (s_cnt != baseball[i][1] || b_cnt != baseball[i][2]) {
				number_list[j] = 0;
			}
		}
	}
	for (int i = 0; i < number_list.size(); i++) {
		if (number_list[i] != 0) {
			answer++;
		}
	}
	return answer;
}