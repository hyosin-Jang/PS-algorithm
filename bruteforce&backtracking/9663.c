#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n;
int board[15];

// 유망성 판단 함수
int promising(int cdx) {
	
	// 같은 열, 대각선 X
	for (int i = 0; i < cdx; i++) {
		if (board[i] == board[cdx] || cdx - i == abs(board[cdx] - board[i])) {
			return 0; // false
		}
	}
	return 1;


}

// nqueen 알고리즘
void nqueen(int cdx) {
	// cdx가 마지막 행까지 수행하고 여기까지 오면, 찾기 완료
	if (cdx == n) {
		count++;
		return;
	}
	for (int i = 0; i < n; i++) {
		board[cdx] = i; // cdx번째 행, i번째 열에 queen을 놓아본다.
		if (promising(cdx)) { // 그 자리에 두어도 괜찮다면,
			nqueen(cdx + 1); // 그 다음행에 퀸을 놓아본다.
		}
	}

}
int main() {

	scanf("%d",&n);
	nqueen(0);
	printf("%d",count);

	return 0;
}