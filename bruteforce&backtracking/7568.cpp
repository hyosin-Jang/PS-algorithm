#include<iostream>

using namespace std;

// Å°, ¸ö¹«°Ô
pair<int, int>p[50];
int r[50];

void compareRank(int N) {
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (p[i].first > p[j].first && p[i].second > p[j].second)
                r[j]++;
        }
    }
}

void printRank(int N) {
    for (int i = 0 ; i < N ; i++) {
        cout << r[i] + 1 << " ";
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0 ; i < N ; i++)
        cin >> p[i].first >> p[i].second;
    
    compareRank(N);
    printRank(N);

    return 0;
}
