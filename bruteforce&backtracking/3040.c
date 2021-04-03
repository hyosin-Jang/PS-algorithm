#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int height[9];
	int dwarf7[7];
	int sum = 0, c=0, tmp=0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
		sum += height[i];
	}
	for (int i = 0; i < 8;i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((sum - (height[i] + height[j])) == 100) {
				for (int k = 0; k < 9; k++)
					if (k != i && k != j)
						dwarf7[c++] = height[k];
				return;
			}

		}
	}
  // 오름차순 bubble sort
	for (int i = 0; i < 7; i++) {
		for (int j = i; j < 6;j++) {
			if (dwarf7[j] > dwarf7[j + 1]) {
				tmp = dwarf7[j + 1];
				dwarf7[j + 1] = dwarf7[j];
				dwarf7[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 7; i++)
		printf("%d\n",dwarf7[i]);

	return 0;
}