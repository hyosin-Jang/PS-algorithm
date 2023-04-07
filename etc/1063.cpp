#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 8;
int board[SIZE][SIZE];


queue <string> q;
string king, stone;
int N;

// R, L, B, T, RT, LT, RB, LB
int X[8] = { 1,-1, 0 , 0, 1, -1, 1, -1};
int Y[8] = { 0, 0, 1, -1, -1, -1, 1, 1};
int kx, ky, sx, sy;

int main() {
	cin >> king >> stone >> N;

	// 현재 위치 계산
	kx = king[0] - 'A';
	ky = 8-(king[1] - '0');
	sx = stone[0] - 'A';
	sy = 8 - (stone[1] - '0');

	for (int i = 0; i < N; i++) {
		string tmp;
		int dir=-1;
		cin >> tmp;
		if (tmp == "R") dir = 0;
		else if (tmp == "L") dir = 1;
		else if (tmp == "B") dir = 2;
		else if (tmp == "T") dir = 3;
		else if (tmp == "RT") dir = 4;
		else if (tmp == "LT") dir = 5;
		else if (tmp == "RB") dir = 6;
		else if (tmp == "LB") dir = 7;
		
		int nextX = kx + X[dir];
		int nextY = ky + Y[dir];
		//cout << nextX << nextY << "\n";

		if (nextX >= 0 && nextX <= 7
			&& nextY >= 0 && nextY <= 7)
		{
			int s_nextX = sx + X[dir];
			int s_nextY = sy + Y[dir];
			// 돌 위치 체크
			if (nextX == sx && nextY == sy) {
				if (s_nextX >= 0 && s_nextX <= 7
					&& s_nextY >= 0 && s_nextY <= 7) {
					sx = s_nextX;
					sy = s_nextY;
					kx = nextX;
					ky = nextY;
					
				}
			}
			else {
				kx = nextX;
				ky = nextY;
			
			}
	
		}
	}

	cout << (char)(kx + 'A') << SIZE - ky << "\n";
	cout << (char)(sx + 'A') << SIZE - sy << "\n";

	return 0;
}
