#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll N; int d;


ll change(ll x, ll y) {
    string s = "";
    while (x > 0) {
        s += (x % y + '0');
        x /= y;
    }
    reverse(s.begin(), s.end());

    return stoll(s);
}

ll sol(ll x) {

    int exist[10] = { 0 }; //딱 한 개만 등장해야 됩니다
    string t = to_string(x);

    string max = "";

    // d진법의 가장큰숫자
    for (int i = d - 1;i >= 0;i--) {
        max += to_string(i);
    }

    //   cout<<max<<'\n';


    for (ll i = x + 1;i <= stoll(max);i++) {

        memset(exist, 0, sizeof(exist));
        int is_ans = 1;

        string tmp = to_string(i);

        if (tmp.length() != d) continue;
        //   cout<<i<<'\n';

        for (int j = 0;j < tmp.length();j++) {
            cout << "tmp[j]: " << tmp[j] << "\n";

            // tmp[j] = 3
            if (tmp[j] - '0' >= d) break; // d진법이므로 d보다 같거나 큰 수가 나오면 안 됨
            
            if (exist[tmp[j] - '0'] > 1) { is_ans = 0;break; } //2번이상 나온 경우
            
            // 존재한다고 하나 올리기
            exist[tmp[j] - '0']++;
            //   cout<<exist[tmp[i]-'0']<<" ";
        }


        // 한 번도 안나온 경우
        for (int j = 0;j < d;j++) {
            if (exist[j] == 0) { is_ans = 0;break; } // 한 번도 안나온 경우
        }


        if (is_ans) {
            ll k = 1, ans = 0;
            for (int j = d - 1;j >= 0;j--) {//10진법으로 바꾸기
                ans += k * (tmp[j] - '0');
                k *= d;
            }

            return ans;
        }

    }

    return -1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> d;

    // 
    ll x = change(N, d);
     //  cout<<x<<'\n';
    ll k = sol(x);
    //   cout<<k;
    if (k == -1) { cout << -1;return 0; }
    cout << k;
    return 0;
}
