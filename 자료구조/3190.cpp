#include <cstdio>

int a[101][101]; //보드
int x[11111], y[11111];
char v[11111];
char t[4];

// 아래, 오른쪽, 위, 왼쪽
int px[4] = { 0, 1, 0, -1 };
int py[4] = { 1, 0, -1, 0 };

int main() {
	int i, j, k, l, n, m;
	scanf("%d%d", &n, &m); // 보드 크기, 사과 개수
	while (m--) { // 사과 입력
		scanf("%d%d", &i, &j);
		a[i][j] = 1; // 사과 위치 1로 표시
	}
	scanf("%d", &m); // 방항 변환 횟수 L
	while (m--) {
		scanf("%d%s",&k, t);
		v[k + 1] = t[0]; // 3 D면, v[4] = D 저장
	}
	i = 1;
	j = k = l = 0;
	for (m = 1;; m++) {
		i += px[k]; // 다음 위치
		j += py[k];
		if (i<1 || j<1 || i>n || j>n || a[i][j] < 0) break;
		if (!a[i][j]) { // 다음 위치에 사과가 없다면
			a[x[l]][y[l]] = 0; // 이전 위치 0으로 바꾸기
			l++;
		}
		x[m] = i;
		x[m] = j;
		a[i][j] = -1; // 뱀 몸통 있으면 -1
		if (v[m] == 'L') k = k + 3 & 3;
		if (v[m] == 'D') k = k + 1 & 3;	
	}
	printf("%d", m-1);
}
