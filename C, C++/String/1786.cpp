#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

vector<int> getPi(string p){
    int m = p.size(), j = 0;
    vector<int> pi(m, 0);

    for(int i=1 ; i<m  ; i++){
        while(j > 0 && p[i] != p[j]){
            j = pi[j-1];
        } if(p[i] == p[j]){
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> kmp(string t, string p){
    int n = t.size(), m = p.size(), j =0;
    auto pi = getPi(p);

    vector<int> ans;

    for(int i = 0 ; i < n ; i++){
        while(j > 0 && p[j] != t[i]){
            j = pi[j-1];
        } if(p[j] == t[i]){
            if(j == m-1){
                ans.push_back(i + 2 - m);
                cnt++;
                j = pi[j];
            } else j++;
        }
    }
    return ans;
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string t, p;
    getline(cin, t);
    getline(cin, p);
    //cin >> t >> p;

    auto ans = kmp(t, p);

    cout << cnt << "\n";
    for(int i = 0 ; i< ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    
    return 0;
}