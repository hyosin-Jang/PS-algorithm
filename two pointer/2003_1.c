//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int n, m, result = 0;
//	int A[10000];
//	int low = 0, high = 0,sum=0;
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++)
//		scanf("%d", &A[i]);
//
//	// ������ �ε��� �����ϱ�
//	// low �̻�, high �̸�
//	while (high <= n) {
//		// �κ����� m���� ũ�ų� ���ٸ�, low �� ���� ������Ű��
//		if (sum >= m)
//			sum -= A[low++];
//		// �κ����� m���� �۴ٸ�, high �� ���ϰ�, ������Ű��
//		else if (sum < m)
//			sum += A[high++];
//		if (sum == m)
//			result++;
//	}
//	printf("%d", result);
//
//	return 0;
//}