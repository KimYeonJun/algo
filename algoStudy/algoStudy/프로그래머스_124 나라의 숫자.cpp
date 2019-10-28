#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n) {
	string answer = "";
	while (n > 0) {
		int b = n % 3;
		if (b == 1) {
			answer += "1";
			n = n / 3;
		}
		else if (b == 2) {
			answer += "2";
			n = n / 3;
		}
		else if (b == 0) {
			answer += "4";
			n = n / 3;
			n = n - 1;
		}
	}

	reverse(answer.begin(), answer.end());

	return answer;
}