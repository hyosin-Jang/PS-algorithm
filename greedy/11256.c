#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int N, i=0, c=0, tmp=0; // �׽�Ʈ ���̽� number
	int candy_num = 0, box_num = 0;
	int width[1000]; // ���� �迭
	int height[1000]; // ���� �迭
	int mul[1000]; //�� �迭
	int box_min_num[10] = {0};


	scanf("%d",&N);

	for (int k = 0; k < N; k++) {
		scanf("%d %d", &candy_num, &box_num);

		//������ ����ϱ�
		for (i = 0; i < box_num; i++) {
			scanf("%d %d", &width[i], &height[i]);
			mul[i] = width[i] * height[i];
		}

		// mul�� ��������
		for (int j = box_num; j > 0; j--) {
			for (int i = 0; i < j-1; i++) {
				if (mul[i] < mul[i + 1]) {
					tmp = mul[i + 1];
					mul[i + 1] = mul[i];
					mul[i] = tmp;
				}
			}
		}
		i = 0;

		while (candy_num > 0) {
			candy_num -= mul[i];
			box_min_num[c] += 1;
			i++;
		}
		c++;
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", box_min_num[i]);
	}

	return 0;
}