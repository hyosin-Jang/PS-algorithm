#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L, K;
vector <pair<int, int>> v;
int score[101];
int sum;

int main() {
	int easy, difficult;
	cin >> N >> L >> K;

	for (int i = 0; i < N; i++) {
		cin >> easy >> difficult;
		v.push_back(make_pair(easy, difficult));
	}

	for (int i = 0; i < N; i++) {
			if (v[i].second <= L) 		
				score[i] = 140;		
			else if (v[i].first <= L) 
				score[i] = 100;	
	}

	sort(score, score + N, greater<int>());

	for(int i =0 ; i < K ; i++)
		sum += score[i];

	cout << sum << endl;

	return 0;
}
