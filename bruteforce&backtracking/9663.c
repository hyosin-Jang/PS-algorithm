#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n;
int board[15];

// ������ �Ǵ� �Լ�
int promising(int cdx) {
	
	// ���� ��, �밢�� X
	for (int i = 0; i < cdx; i++) {
		if (board[i] == board[cdx] || cdx - i == abs(board[cdx] - board[i])) {
			return 0; // false
		}
	}
	return 1;


}

// nqueen �˰���
void nqueen(int cdx) {
	// cdx�� ������ ����� �����ϰ� ������� ����, ã�� �Ϸ�
	if (cdx == n) {
		count++;
		return;
	}
	for (int i = 0; i < n; i++) {
		board[cdx] = i; // cdx��° ��, i��° ���� queen�� ���ƺ���.
		if (promising(cdx)) { // �� �ڸ��� �ξ �����ٸ�,
			nqueen(cdx + 1); // �� �����࿡ ���� ���ƺ���.
		}
	}

}
int main() {

	scanf("%d",&n);
	nqueen(0);
	printf("%d",count);

	return 0;
}