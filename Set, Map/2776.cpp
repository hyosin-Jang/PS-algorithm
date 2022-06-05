#include <iostream>
#include <set>
using namespace std;


int main() {

	// 정렬을 할 필요 없이 삽입과 검색만 일어나는 문제임
	// 입력의 수가 최대 1,000,000으로 삽입과 탐색이 많이 일어남
	// 따라서 O(logN)의 set이 아니라 O(1)인 unordered_set을 사용해서 풀어야 함
	// unordered_set: O(1)이고, 정렬 없이 삽입과 탐색할 때만 사용함
	// Q. 탐색을 하려면 정렬되어 있는게 더 빠르지 않을까?
	// 근데 왜 정렬이 안되어 있는데, 시간복잡도가 더 적게 걸리지??

	// unordered_set은 어떤 경우에 사용할까?
	// => unordered_set은 찾기/삽입할 때는 해시 테이블로 구현됨 그래서 O(1)로 찾음
	// set, unordered_set, multiset 차이점 알아보기!
  
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, n1, n2, tmp;
	cin >> t;

	while (t--) {
		cin >> n1;

		set <int> note1; // tc여러 개 이므로 초기화해주기

		for (int i = 0; i < n1; i++) {
			cin >> tmp;
			note1.insert(tmp);
		}

		cin >> n2;
		for (int i = 0; i < n2; i++) {
			cin >> tmp;
			if (note1.find(tmp) != note1.end()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		
		}
		
	}

	return 0;
}
