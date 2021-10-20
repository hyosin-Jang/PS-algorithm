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
// lottos_len�� �迭 lottos�� �����Դϴ�.
// win_nums_len�� �迭 win_nums�� �����Դϴ�.


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int l = 0, w = 0, count=0, zero_num = 0; // �ְ� ����, ���� ����, �ζ� ������, ���� ������


    // lottos�� win_nums ����
    sort(lottos.begin(), lottos.end()); 
    sort(win_nums.begin(), win_nums.end());

    for (; l < lottos.size() && w < win_nums.size(); ) {
   
        if (lottos[l] == 0) {
            zero_num++;
            l++; // �� ĭ ���������� �̵�
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