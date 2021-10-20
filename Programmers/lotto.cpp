#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;


int getNum(int count) {

    switch (count) {
    case 6:
        return 1;
    
    case 5:
        return 2;
      
    case 4:
        return 3;
     
    case 3:
        return 4;
      
    case 2:
        return 5;
       
    default:
        return 6;
     
    }

}
// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int l = 0, w = 0, count=0, zero_num = 0; // 최고 순위, 최저 순위, 로또 포인터, 정답 포인터


    // lottos와 win_nums 정렬
    sort(lottos.begin(), lottos.end()); 
    sort(win_nums.begin(), win_nums.end());

    for (; l < lottos.size() && w < win_nums.size(); ) {
   
        if (lottos[l] == 0) {
            zero_num++;
            l++; // 한 칸 오른쪽으로 이동
        }
        else {
            if (lottos[l] == win_nums[w]) {
                count++;
                l++; w++;
            }
            else if (lottos[l] > win_nums[w]) {
                w++;
            }
            else {
                l++;
            }
        }
    }
    return { getNum(count + zero_num), getNum(count) };

}

int main() {
    vector <int> lottos = { 44, 1, 0, 0, 31, 25 };
    vector <int> win_num = { 31, 10, 45, 1, 6, 19 };
    
    vector<int> answers = solution(lottos, win_num);

    for (int answer : answers) {
        cout << answer << " ";
    }

    cout << "\n";

    return 0;

}