//#include <stdio.h>
//#include <stdlib.h>
//
////���������� ����
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
//// �迭 �ȿ� �����ϴ��� üũ�ϴ� �Լ�
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
//    //A[]�� ����
//    for (int i = 0; i < N; i++)
//        scanf("%d", &A[i]);
//
//    //����Ʈ �����Լ�
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