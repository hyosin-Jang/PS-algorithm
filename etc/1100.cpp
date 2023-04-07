#include <iostream>
using namespace std;

int main() {
    
	char std[9];
	int chk = 0, num = 0;
    
	for (int i = 0; i < 8; i++) {
		scanf("%s", std);
		for (int j = num; j < 8; j+=2) {
			if (std[j] == 'F'){
				chk++;		
			}
		}
		if (num == 0) {
			num = 1;
		}else num = 0;
	}
	printf("%d\n", chk);
}
