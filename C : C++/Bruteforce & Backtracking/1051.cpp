#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

// k는 변의 길이
// result는 1부터 시작함 (초기값은 1)
// max, min 함수는 algorithm 헤더에 있음
// 한줄에 여러 정수 입력받을 때, string 으로 입력받기

const int MAX = 50;
int square[MAX][MAX];
int N, M;

int maxSquare() {
	int result = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < min(N, M); k++) {
				if (i + k < N && j + k < M &&
					square[i + k][j] == square[i][j] && square[i + k][j + k] == square[i][j]
					&& square[i][j] == square[i][j + k])
					result = max(result, k + 1);
			}
		}
	}

	return result * result;
}

int main() {

	cin >> N >> M;

	for (int i= 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < M; j++)
			square[i][j] = temp[j] - '0';
	
	}

	cout << maxSquare() << endl;

	return 0;
}
