#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���� �������� ����׷�����, 
// ��� �������� �����ؾ� �ϴϱ�
// �ּ� ������ ���� = (���� -1) ��
int main() {
	int t, n ,m, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &a, &b);
		printf("%d\n", n-1);
	}
}