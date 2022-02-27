#include<iostream>
#include<string>
using namespace std;

string s;
int l = 0, r = 0;

int main(void) {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == '(') l++;
        else r++;
        if (l < r) { //)가 더 큰 경우가 생기면 그것 포함 그 전의 ) 중 하나 삭제해야함 
            cout << r << "\n";
            return 0;
        }
        else if (l == r) { // ㅣ은 앞이 짝이 다 맞춰져있어서 지우면 안됨
            l == 0;
        }
    }
    //front (( 인 경우 l, (직후에 )가 나오는 경우 ㅣ-1
    //end ))인 경우 r, 직전에 ( ) 인경우 r-1 
    if (l > r && s.at(1) == '(') cout << l << "\n";
    else if (l > r) cout << l - 1 << "\n";
    else if (s.at(s.length() - 2) == ')') cout << r << "\n";
    else cout << r - 1 << "\n";
    return 0;
}
