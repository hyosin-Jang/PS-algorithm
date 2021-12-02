#include<iostream>
#include<vector>
using namespace std;

int solution(int n,int m) {
	vector<vector<int>> v(n+1,vector<int>(m+1,0));
	for(int i=1;i<=m;i++)	
		v[1][i] = i;
	
	for(int i=2;i<=n;i++) {
		for(int j=i;j<=m;j++) {
			if(j == i) {
				v[i][j] = 1;
				continue;
				}
			 for(int k=i-1; k<=j-1;k++) 
				v[i][j] += v[i-1][k];
		}
	}

	return v[n][m];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int n,m,T;
	cin >> T;
	while(T--) {
	cin >> n >> m;
	cout <<solution(n,m)<<"\n";
	}
	return 0;
}
