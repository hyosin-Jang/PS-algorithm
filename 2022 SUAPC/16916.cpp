#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

string S, P;

vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector <int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && pattern[i] != pattern[j])  // i,j 다르면 j만 뒤로 이동
            j = table[j - 1]; // table의 전칸에 적혀있는 값으로 이동하기
        
        if (pattern[i] == pattern[j])
            table[i] = ++j; // j에 적힌 수보다 하나 큰 수 적기
    
    }
    return table;
}

int KMP(string S, string P) {
    vector<int> table = makeTable(P);
    int j = 0;

    for (int i = 0; i < S.length(); i++) {     
        while (j > 0 && S[i] != P[j]) {
            j = table[j - 1];
        }
        if (S[i] == P[j]) {
            if (j == P.length() - 1) return 1;     
            else j += 1;
        }
    }
    return 0;

}

int main() {

	cin >> S >> P;

	cout << KMP(S, P) << endl;


	return 0;
}
