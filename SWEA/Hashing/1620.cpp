#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, M;

map<int, string> id;
map<string, int> name;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string pokemon;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> pokemon;
    id[i] = pokemon;
    name[pokemon] = i;
  }

  while (M--) {
    cin >> pokemon;

    // 숫자면 문자 출력
    if (isdigit(pokemon[0])) {
      cout << id[stoi(pokemon)] << "\n";
    } else {
      cout << name[pokemon] << "\n";
    }
  }

  return 0;
}