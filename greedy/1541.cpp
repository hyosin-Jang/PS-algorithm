#include <iostream>
#include <string>
using namespace std;

string str;
string temp = "";
int result = 0;

int main() {
	cin >> str;
	bool minus = false;

	// 문자열에서 +랑 -를 기준으로 split 하기 
	for (auto i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus) { // minus 괄호로 묶여있으면 계속 빼주기
				result -= stoi(temp);
			}
			else {
				result += stoi(temp);
			}
			temp = "";
			if (str[i] == '-') {
				minus = true;
			}	
		}
		else {
			temp += str[i]; // 숫자가 아니라 문자열이여서 자릿수 계산할 필요 없음
		}
	}

	cout << result; 


	return 0;
}
