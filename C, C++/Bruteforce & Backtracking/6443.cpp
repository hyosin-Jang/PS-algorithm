#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int len;

// 단어의 최대 길이가 20이므로 방문 처리 + Set을 이용하면 TLE가 발생할 수 있다.
// dfs 조합에서 같은 문자가 있을 때 중복 처리 - visited 대신 Swap을 이용한다.
void dfs(string s, int idx){
    if(idx == len-1){
        cout << s<< "\n";
        return;
    }
    for(int i = idx ; i < len ; i++){
        if(i!=idx && s[i] == s[idx]) continue;
        if(s[i]!= s[idx]){ // swap
            char c = s[i];
            s[i] = s[idx];
            s[idx] = c;
        }
        dfs(s, idx+1);
    }
}
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while(N--){
        cin >> str;
        len = str.size();
        sort(str.begin(), str.end());
        dfs(str, 0);
    }
    return 0;
}