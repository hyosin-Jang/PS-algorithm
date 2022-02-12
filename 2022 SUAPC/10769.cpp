#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;

    getline(cin, s);

    int SmileCnt = 0, SadCnt = 0;

    for (int i = 0; i < s.length(); i++){
        if (i < s.length() - 3 && s[i] == ':' && s[i + 1] == '-' && s[i + 2] == ')')
            SmileCnt++;
        else if (i < s.length() - 3 && s[i] == ':' && s[i + 1] == '-' && s[i + 2] == '(')
            SadCnt++;
    }

    if (!SmileCnt && !SadCnt) cout << "none\n";
    else if (SmileCnt == SadCnt) cout << "unsure\n";
    else if (SmileCnt > SadCnt) cout << "happy\n";
    else cout << "sad\n";

    return 0;

}
