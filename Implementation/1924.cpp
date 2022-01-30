#include <iostream>
using namespace std;

string arr[7] = {  "SUN" ,"MON", "TUE", "WED", "THU", "FRI", "SAT"};
int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
	int x, y;

	// x월 y일
	cin >> x >> y;

	for (int i = 0; i < x-1 ; i++) {
		y += days[i];
	}
	cout << arr[y % 7] << endl;



	return 0;
}
