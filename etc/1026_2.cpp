#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> A, B;

bool cmp(int num1, int num2){
        return num1 > num2;
}

int minResult(void){
        sort(A.begin(), A.end(), cmp);
        sort(B.begin(), B.end());

        int result = 0;
        for (int i = 0; i < N; i++)
                 result += (A[i] * B[i]);
        return result;
}

int main(void){
        cin >> N;

        for (int i = 0; i < N; i++){
                 int temp;
                 cin >> temp;
                 A.push_back(temp);
        }

        for (int i = 0; i < N; i++){
                 int temp;
                 cin >> temp;
                 B.push_back(temp);

        }

        cout << minResult() << endl;

        return 0;

}
