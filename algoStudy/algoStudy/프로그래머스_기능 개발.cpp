#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> que;
	/*
	   ------version 1.0----------------

	     for(int i=0;i<progresses.size();i++){
	         que.push(100-progresses[i]);
	     }
	     int idx=0;
	     while(!que.empty()){
	         int q_size=que.size();
	         for(int i=0;i<q_size;i++){
	             int prog = que.front();
	             que.pop();
	             prog -= speeds[i];
	             que.push(prog);
	         }
	         int res=0;

	         while(que.front()<=0){
	             que.pop();
	             //progresses[idx++].erase();
	            // speeds.erase(speeds.begin());
	             res++;
	         }
	         answer.push_back(res);
	     }
		 */


	//version 2.0
	for (int i = 0; i < progresses.size(); i++) {
		int tmp = (100 - progresses[i]) % speeds[i];

		if (tmp == 0) {
			que.push((100 - progresses[i]) / speeds[i]);
		}
		else
			que.push((100 - progresses[i]) / speeds[i] + 1);
	}
	while (!que.empty()) {
		int cnt = 1;
		int cur = que.front(); que.pop();

		while (cur >= que.front() && !que.empty()) {
			cnt++;
			que.pop();
		}
		answer.push_back(cnt);
	}
	
	return answer;
}