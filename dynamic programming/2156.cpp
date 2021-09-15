#include <iostream>

#define MAX 10010
using namespace std;

int N;
int arr[MAX];
int d[MAX];

int max(int A, int B) { 
    if (A > B) 
        return A; 
    return B; 
}

void Input(){

    cin >> N;

    for (int i = 1; i <= N; i++) 
        cin >> arr[i];
}

void Solution(){
    d[1] = arr[1];
    d[2] = d[1] + arr[2];

    for (int i = 3; i <= N; i++){

        d[i] = max(d[i - 3] + arr[i - 1] + arr[i], d[i - 2] + arr[i]);
        d[i] = max(d[i - 1], d[i]);

    }
    cout << d[N] << endl;
}

void Solve(){

    Input();
    Solution();
}

int main(void){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
