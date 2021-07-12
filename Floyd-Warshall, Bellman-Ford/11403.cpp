//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//const int INF = 100000;
//const int MAX_VERTICES =101;
//int A[MAX_VERTICES][MAX_VERTICES];
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	int n, i, j, k;
//	cin >> n;
//	
//	// 배열 초기화
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++) {
//			cin >> A[i][j];
//			if (A[i][j] == 0) A[i][j] = INF;
//		}
//
//	for (k = 0; k < n; k++) {
//		for (i = 0; i < n; i++)
//			for (j = 0; j < n; j++) {
//				if (A[i][k] + A[k][j] < A[i][j])
//					A[i][j] = A[i][k] + A[k][j];
//			}
//	}
//
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n; j++) {
//			if (A[i][j] == INF)
//				cout << 0 << ' ';
//			else
//				cout << 1 << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}
