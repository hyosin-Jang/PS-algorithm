#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int int64_t
// https://educoder.tistory.com/entry/cc-int8t-uint8t-int16t-uint16t
// int8_t, uint8_t, int16_t, uint16_t

// int64_t: _WORDSIZE가 64라면 long int, 아니라면 long long int
// int32_t: int

int N;
int V[100001];
vector<int> L(100001, 0), R(100001, 0);

int ans = 0;
int32_t main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1 ; i <= N ; i++){
        cin >> V[i];
        R[V[i]]++;
    }
    R[V[1]]--;
    int mx = *max_element(V + 1, V + N + 1);

    for(int i = 2 ; i <= N-1 ; i++){
        // i: v[i] 중심이 되는 부분
        L[V[i-1]]++, R[V[i]]--;
        ans += L[V[i]] * R[V[i]]; 
      
        for(int j = 1 ; 1 <= V[i] - j && V[i] + j <= mx ; j++){
            ans += L[V[i] - j] * R[V[i] + j];
            ans += L[V[i] + j] * R[V[i] - j];
        }
    }

    cout << ans << "\n";

    return 0;
}