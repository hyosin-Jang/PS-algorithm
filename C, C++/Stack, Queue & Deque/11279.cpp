#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int main() {
	priority_queue<int, vector<int>> q;
	int n, x;
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);
		if (x == 0 && q.empty())
			printf("0\n");
		else if (x == 0)
		{
			printf("%d\n", q.top());
			q.pop();
		}
		q.push(x);
	}

	return 0;

}
