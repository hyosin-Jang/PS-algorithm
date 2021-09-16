#include <iostream>

#define MAX 101
#define mod 1000000000

using namespace std;

int N;
long long result;
long long d[MAX][11];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= 9; i++){
        d[1][i] = 1;  
    }
    d[1][0] = 0;

    for (int i = 2; i <= N; i++){
        for (int j = 0; j <= 9; j++){

            if (j == 0) d[i][j] = d[i - 1][j + 1] % mod;

            else if (j == 9) d[i][j] = d[i - 1][j - 1] % mod;

            else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
        }
    }

    for (int i = 0; i < 10; i++)
        result += d[N][i];
    
    cout << result % mod << endl;

    return 0;
}
