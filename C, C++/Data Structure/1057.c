#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, kim, im,cnt=1;
	scanf("%d %d %d",&N, &kim, &im);

	while(N) {
		if ((kim+1)/2 == (im+1)/2)
			break;
		kim = (kim + 1) / 2;
		im = (im + 1) / 2;
		cnt++;
		N /= 2;
	}
	if (!N)
		printf("-1");
	else
		printf("%d",cnt);

	return 0;
}