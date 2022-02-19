#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, rest_time = 0, last=0;
int start_time=0, finish_time=0;
int max_time;
vector <pair<int, int>> v;

bool compare(pair<int,int> v1, pair<int, int> v2) {
	return v1.first < v2.first;
}

// 10분 더하는 함수
int CalculatePlus10(int num) { // 1859
	int last_num = num % 100; //00
	if (last_num >= 50) { //  
		int first_two_num = num / 100; // 18
		return (first_two_num + 1) * 100 + (last_num-50); // 1909
	}
	else
		return num + 10; //59
}

// 10분 빼는 함수
int CalculateMinus10(int num) { // 1909 => 1859
	int last_num = num % 100; //9
	if (last_num < 10) { 
		int first_two_num = num / 100; // 19
		return (first_two_num -1) * 100 + 50 + last_num;
	}
	else
		return num - 10;
}
 // 1749, 1503
int CalculateTime(int bigger, int smaller) {

	int final_minute=0;

	int bigger_minute = bigger % 100; // 49
	int smaller_minute = smaller % 100; // 03

	int bigger_first_two_num = bigger / 100; // 17
	int smaller_first_two_num = smaller / 100; //15

	if (bigger_first_two_num != smaller_first_two_num) {
		int diff = bigger_first_two_num - smaller_first_two_num; // 2
		final_minute = bigger_minute + diff * 60 - smaller_minute; // 49 120 03
	}
	else 
		final_minute = bigger_minute - smaller_minute;
	
	return final_minute;
}

int main() {
	cin >> N;

	int start=0, end=0, tmp_time=0;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end(), compare);

	if (v[0].first > 1010)
		start_time = CalculateTime(CalculateMinus10(v[0].first), 1000);

	//cout << "start_time: " << start_time << "\n";

	// 놀이기구 사이 쉬는 시간 계산
	for (int i = 0; i < N-1; i++) {
		last = max(last, v[i].second);

		int plus10 = CalculatePlus10(v[i].second);
		int minus10 = CalculateMinus10(v[i + 1].first);
		//cout << plus10 << " " << minus10 << "\n";
		if (plus10 < minus10 &&  minus10 > last) {
			tmp_time = CalculateTime(minus10, plus10);
		}
		//cout << "tmp_time: " << tmp_time << "\n";

		rest_time = max(rest_time, tmp_time);
		
	}
	// 오후 10시 - 마지막 놀이기구 쉬는시간 계산
	if (2150 > v[N - 1].second) {
		finish_time = CalculateTime(2200, CalculatePlus10(v[N - 1].second));
	}
	//cout << "finish_time: " << finish_time << "\n";


	if ((start_time == finish_time) && (start_time == rest_time) && (start_time==0)) {
		cout << "0\n";
		return 0;
	}
	max_time = max(start_time, finish_time);
	max_time = max(max_time, rest_time);

	cout << max_time << "\n";

	return 0;
}
