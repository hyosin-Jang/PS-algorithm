#include <iostream>
#include <map>
using namespace std;

int main() {
	int N, M, K, key, value, num;
	cin >> N >> M >> K;
	map <int, int> db;

	for (int i = 0; i < N; i++) {
		cin >> key >> value;
		db.insert(make_pair(key, value));
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (num == 1) {
			// 해당 키와 value를 가진 데이터 추가
			cin >> key >> value;
			db.insert(make_pair(key, value));
		}
		else if (num == 2) {
			cin >> key >> value;
			// 1. 해당 key가 있는지 조사. 

		
		}
		else { // num==3
		
		}
	}

	//testMap.insert(make_pair(2, "두 번째 방법"));
	//testMap.emplace(4, "4번째 방법");
	//testMap.insert_or_assign(5, "다섯 번째 방법");

	//testMap.erase(3);

	//for (auto& myPair : testMap)
	//	cout << myPair.first << " " << myPair.second << endl;


	return 0;
}
