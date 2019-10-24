#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> bridge_truck;

	int truck_cnt = 0;
	int truck_cnt2 = 0;
	int bridge_weight = 0;
	while (truck_cnt < truck_weights.size()) {

		int cur_truck = truck_weights[truck_cnt];
		if (bridge_weight + cur_truck <= weight) { //무게 체크
			bridge_weight += cur_truck;
			bridge_truck.push(bridge_length);
			truck_cnt++;
		}
		int tmp = bridge_truck.size();
		for (int i = 0; i < tmp; i++) {
			int cur = bridge_truck.front();
			bridge_truck.pop();
			cur--;
			bridge_truck.push(cur);
		}
		if (bridge_truck.front() == 0) {
			bridge_weight -= truck_weights[truck_cnt2]; //truck_cnt2
			truck_cnt2++;
			bridge_truck.pop();
		}

		answer++;
	}
	answer += bridge_length;

	return answer;
}