#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100

int main() {

	int n, m, sum=0, max=0;
	int card[SIZE];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n;j++) {
			for (int k = j + 1; k < n; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum > max && sum <= m)
					max = sum;
			}
		}
	}
	printf("%d\n", max);
	return 0;




	return 0;
}