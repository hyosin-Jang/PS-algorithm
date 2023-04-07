#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int num, tmp;
    vector<int> a;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    // 배열의 시작점 주소와 마지막 주소+1
    sort(a.begin(), a.end());
    for (int i = 0; i < num; i++)
        cout << a[i] << '\n';
}