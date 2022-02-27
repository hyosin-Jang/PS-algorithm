#include <iostream>
using namespace std;

int N;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	string s;
	cin >> s;

	int answer = 0;
	int tree, grass, fence, people;
	tree = grass = fence = people = 0;

	// i를 3씩 더하고
	for(int i =3 ; i<=N ; i+=3){
		for (int j = 0; j < N - (i-1); j++) {
			//cout << "i: " << i << " j: " << j << "\n";
			tree = grass = fence = people = 0;
			for (int k = j; k <= j + i - 1; k++) {
				//cout << "j: " << j << " k: " << k << "\n";
				if (s[k] == 'T') tree++;
				else if (s[k] == 'G') grass++;
				else if (s[k] == 'F') fence++;
				else people++;
			}
			//cout << "t: " << tree << " g: " << grass << " f:" << fence << " p: " << people << "\n";
			if (tree % 3 == 0 && grass % 3 == 0 && fence % 3 == 0 && people % 3 == 0)
				answer++;
			//cout << "answer: " << answer << "\n";
		}
	}

	cout << answer << endl;


	return 0;
}
