#include <iostream>

using namespace std;

int cnt = 0, N, board[15];

// 백트래킹 사용
// 경우의 수를 줄인다는 점(가지치기)에서
// DFS랑 다름
int promising(int cdx) {

	// 같은 열X, 대각선X
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i]))
			return 0;
	}

	return 1;
}

// nqueen 알고리즘 수행
void nqueen(int cdx) {

	// cdx가 마지막 행까지 수행하고 여기까지 오면 찾기 완료
	if (cdx == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		board[cdx] = i; // cdx번째 행, i번째 열에 queen을 놓아본다.
		// 그 행에 대해 유망성을 판단한다.
		if (promising(cdx)) {
			nqueen(cdx + 1); // cdx+1번째 행에 대해 퀸을 놓아본다.
		}
	
	}

}

int main() {

	cin >> N;
	nqueen(0);
	cout << cnt << endl;



	return 0;
}
