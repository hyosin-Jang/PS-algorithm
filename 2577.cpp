#include<iostream>
using namespace std;

int main() {
	int a, b, c, result;
	int arr[10] = { 0, }; // �ʱ�ȭ
	cin >> a >> b >> c;
	result = a * b * c;
	while (result > 0) {
		arr[result % 10]++;
		result /= 10;	
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;
	return 0;
}