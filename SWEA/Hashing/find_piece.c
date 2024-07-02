#include <stdio.h>

int N = 15;
int M = 4;

typedef unsigned int ui;

ui hashMap[15][15];
// 4x4 를 hash값 으로 변환
#define gethash(arr, r, c) (((ui)arr[r + 0][c + 0] << 15) | (ui)(arr[r + 0][c + 1] << 14) | (ui)(arr[r + 0][c + 2] << 13) | (ui)(arr[r + 0][c + 3] << 12) | \
							((ui)arr[r + 1][c + 0] << 11) | (ui)(arr[r + 1][c + 1] << 10) | (ui)(arr[r + 1][c + 2] << 9)  | (ui)(arr[r + 1][c + 3] << 8)  | \
						    ((ui)arr[r + 2][c + 0] << 7)  | (ui)(arr[r + 2][c + 1] << 6)  | (ui)(arr[r + 2][c + 2] << 5)  | (ui)(arr[r + 2][c + 3] << 4)  | \
						    ((ui)arr[r + 3][c + 0] << 3)  | (ui)(arr[r + 3][c + 1] << 2)  | (ui)(arr[r + 3][c + 2] << 1)  | (ui)(arr[r + 3][c + 3]))

int first = 1;
char MAP[15][15] =
{
	{ 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, },
	{ 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, },
	{ 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, },
	{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, },
	{ 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, },
	{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, },
	{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, },
	{ 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, },
	{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, },
	{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, },
	{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, },
	{ 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, },
	{ 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, },
	{ 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, },
};

char piece1[4][4] =
{
	{ 1, 0, 0, 1, },
	{ 0, 1, 0, 0, },
	{ 0, 0, 1, 0, },
	{ 0, 0, 0, 1, },
};

char piece2[4][4] =
{
	{ 1, 1, 0, 1, },
	{ 0, 0, 1, 0, },
	{ 0, 1, 0, 0, },
	{ 1, 0, 0, 0, },
};

char piece3[4][4] =
{
	{ 1, 0, 0, 0, },
	{ 0, 1, 0, 1, },
	{ 0, 0, 1, 0, },
	{ 0, 1, 0, 0, },
};


/** type casting 을 이용해서 char 4개를 int 1개로 보고 직접 비교 */
int compare(char MAP[][15], int sr, int sc, char piece[][4]){

    ui cast = 0;

    for(int i = 0 ; i < 4 ; i++){
        if(*(ui*)&MAP[sr + i][sc] != *(ui*)&piece[i][0]) return 0;
    }

    return 1;

    // 완탐
    // for(register int r = 0  ; r < M ; r++){
    //     for(register int c = 0 ; c < M ; c++){
    //         if(piece[r][c] != MAP[sr + r][sc + c]) return 0;
    //     }
    // }
    // return 1;
}


int findPiece(char MAP[][15], char piece[][4]){

    if(first){
        int boundary = N - M;
        
        for(register int r = 0 ; r <= boundary ; r++){
            for(register int c = 0 ; c <= boundary ; c++){
                hashMap[r][c] = getHash(MAP, r, c);
            }
        first = 0;
        }
    }

    int count = 0;
    int boundary = N - M;

    int pieceHash = getHash(piece, 0, 0);

    for(register int r = 0 ; r <= boundary ; r++){
        for(register int c = 0 ; c <= boundary ; c++){
            if(hashMap[r][c] == pieceHash) count++;
        }
    }
    return count;

}

void printBinary(unsigned int a){
    unsigned int mask = 1 << 31;
    for(int i = 0 ; i < 32 ; i++){
        printf("%d", (a & mask) == mask);
        mask >>= 1;
        if(i % 4 == 3) printf(" ");
    }
    putchar('\n');
}

int main(){

    printf("%d\n", *(ui*)&piece1[0][0]);
    printBinary(*(ui*)&piece1[0][0]);

	for (register int tc = 0; tc < 1000000; tc++)
	{
		if (findPiece(MAP, piece1) != 5) printf("wrong!\n");
		if (findPiece(MAP, piece2) != 3) printf("wrong!\n");
		if (findPiece(MAP, piece3) != 3) printf("wrong!\n");
	}

    printf("pass\n");
    
	return 0;
}