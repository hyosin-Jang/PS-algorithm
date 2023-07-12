#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	// 우리
	int cage[10000000] = {0};
	int n, k;
	// loc은 마지막 인덱스
	int ice, loc, max_loc=0, max_ice=0;
	
	// n, k 입력 받기
	scanf("%d %d", &n, &k);

	// n개의 양동이 입력받기 (얼음수, 위치)
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &ice, &loc);
		cage[loc] = ice;
		if (loc > max_loc)
			max_loc = loc;
	}

	// i는 위치 
	for (int i = 0; i <= max_loc; i++) {
		int min = i - k, sum_ice=0, max = i + k;
		if (min < 0) min = 0;
		if (max > max_loc) max = max_loc;
		for (int j = min; j <= max ; j++) {
			sum_ice += cage[j];
		}
		if (max_ice < sum_ice)
			max_ice = sum_ice;
	}
	printf("%d", max_ice);

	return 0;
}