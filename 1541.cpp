#include <iostream>
#include <vector>
using namespace std;

int main() {

	int num=0, sub_result=0, result=0;
	string sign="0"; 
	bool flag=false; // ��ȣ ������ true

	cin >> result;
	while (true) {
		cin >> sign;

		if (sign == "\n")
			break;
		if (sign == "-")
			flag = true;
		cin >> num;

		if (flag == true && sign == "+")
			sub_result += num;
		else if (flag == false && sign == "+")
			result += num;
		else if (flag == true && sign == "-") { // '-'�̸�
			flag = false; // ��ȣ ����
			result -= sub_result;
			sub_result = num;
		}
		else {
			// ��ȣ ���� ���¿��� -
			flag = true;
			sub_result += num;
		}
	}

	cout << result << endl;

	return 0;
}