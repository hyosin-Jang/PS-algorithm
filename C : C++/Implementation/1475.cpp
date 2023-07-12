#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10;
string s;

int arr[MAX], result=0;
int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		arr[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
		if(i!=6 && i!=9)
			result = max(arr[i], result);


	cout << max(result, (arr[6] +arr[9] +1)/2 )<< endl;



	return 0;
}
