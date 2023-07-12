#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50;
char arr[MAX][MAX];
int N;

// 친구인 index만 push
vector<int> check(N);
int friends, twoFriends, gross;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for (int i = 0; i < N; i++)
	{

		friends = 0, twoFriends = 0, gross = 0;
		check.clear();

		// 직접 연결된 친구
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 'Y')
			{
				friends++;
				check.push_back(j);
			}
		cout << "\n"
				 << i + 1 << "번째 friends: " << friends << "\n";

		// 겹친구 확인
		int idx, x;
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 'N')
			{
				// 벡터의 길이까지
				for (int v = 0; v < check.size(); v++)
				{
					idx = check[v]; // 2

					cout << "x: " << j << " idx: " << idx << "\n";
					// x와 y가 연결되어 있으면
					if (arr[j][idx] == 'Y')
					{
						twoFriends++;
						break;
					}
				}
				cout << j + 1 << "번째 twofriends: " << twoFriends << "\n";
			}
		}
		cout << friends + twoFriends << "\n";
		gross = max(gross, friends + twoFriends);
	}

	cout << gross << endl;

	return 0;
}
