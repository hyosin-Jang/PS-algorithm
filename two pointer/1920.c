//#include <stdio.h>
//#include <stdlib.h>
//
////전역변수로 선언
//int A[100000] = { 0 };
//
//int compare(const void* a, const void* b) {
//    if (*(long*)a > *(long*)b)
//        return 1;
//    else if (*(long*)a < *(long*)b)
//        return -1;
//    else return 0;
//}
//
//// 배열 안에 존재하는지 체크하는 함수
//int check_if(int l, int r, int M) {
//    int n = l + r;
//    if (M == A[n / 2]) {
//        return 1;
//    }
//    else if (r <= l || M < A[l] || M > A[r - 1]) {
//        return 0;
//    }
//    else if (M < A[n / 2])
//        return check_if(0, n / 2, M);
//    else
//        return check_if(n / 2, n, M);
//}
//
//int main() {
//    int M, N;
//    long k = 0;
//    scanf("%d", &N);
//
//    //A[]에 저장
//    for (int i = 0; i < N; i++)
//        scanf("%d", &A[i]);
//
//    //퀵소트 내장함수
//    qsort(A, N, sizeof(long int), compare);
//
//    for (int i = 0; i < N; i++)
//        printf("%d", A[i]);
//
//    scanf("%d", &M);
//
//    for (int j = 0; j < M; j++) {
//        scanf("%d", &k);
//        int swtch = check_if(0, N, k);
//        printf("%d\n", swtch);
//    }
//    return 0;
//}