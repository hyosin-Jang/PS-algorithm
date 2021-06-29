#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// �⺻ ���̵��
//1. ����� ������������ �����ϴ� pq1 ����
//   ������ ������������ �����ϴ� pq2 ����
//   (������ ���� ���� �켱������ ���� ����)
//2. x �Է� �ޱ�
//3. x�� 0�̶��, ������ ���� ���� �� ��� �� ����
//4. 0�� �ƴ϶��, �迭�� x�߰�


int N, x;
priority_queue <int, vector<int>, greater<int>> pq1; // ��� �������� ����
priority_queue <int> pq2; // ���� �������� ����

int main() {
	//C++ ǥ�� ��Ʈ������ C ǥ�� ��Ʈ����� ������ ����� ���� �Ŀ� ����ȭ ���� ���θ� ����
	ios_base::sync_with_stdio(0);
	
	// cin�� �ӵ��� ������ �ϱ� ���ؼ� ����ȭ���ִ� ����
	cin.tie(0); 
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			// �Ѵ� ����ִٸ�, 0���
			if (pq1.empty() && pq2.empty()) cout << "0\n";

			else // ���� �ϳ��� ����ְų� �� �� ���Ұ� �ִٸ�
			{
				if (pq1.empty()) {
					cout << pq2.top() << '\n';
					// �� �տ� �ִ� ���� ��ȯ(���� �� ���� ���� ���� ��)
					pq2.pop(); 
				}
				else if (pq2.empty()) {
					cout << pq1.top() << '\n';
					pq1.pop();
				}
				else {
					// �� �� ���Ұ� �ִٸ�, �� ���� �� ���
					if (pq1.top() < -pq2.top()) {
						cout << pq1.top() << '\n';
						pq1.pop();
					}
					else {
						cout << pq2.top() << '\n';
						pq2.pop();

					}
				}
			}
		}
		else if (x > 0) 
			pq1.push(x);
		else
			pq2.push(x);
	}
}