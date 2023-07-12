#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 987654321;

const int MAX = 50;

int N;
int friendsList[MAX][MAX];


void floyd() {
	for (int k = 0; k < N; k++) 
		for(int i =0 ; i< N ; i++)
			for (int j = 0; j < N; j++) {
				if (i == j || j == k || i == k)
					continue;
				else if (friendsList[i][j] > friendsList[i][k] + friendsList[k][j])
					friendsList[i][j] = friendsList[i][k] + friendsList[k][j];
			}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;

		for (int j = 0; j < tmp.size(); j++) {
			if (i == j)
				friendsList[i][j] = 0;
			else
				friendsList[i][j] = tmp[j] == 'Y' ? 1 : INF;
		}
	}

	floyd();

	int result = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			else if (friendsList[i][j] <= 2)
				cnt++;
		}
		result = max(result, cnt);
	
	
	}

	cout << result << endl;

	return 0;
}
