#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 26

int n, k;
int answer = 0;
int alphabet[MAX] = {0,};
int visited[MAX] = {0,};
vector<string> v;


// 83%에서 틀리는 경우
// k가 5인데, 한 단어는 antic만 등장해서 모두 셀 수 있고, 한단어는 anticjj가 등장해서 못세면
// 1을 출력해야 하는데 (셀수 있는 최댓값이니까) 0 출력해서 틀렸다.

int get_word_cnt(){
    int cnt = 0;

    // visited는 단어에 등장한 알파벳에서 k-5개를 방문한 배열
    for(int i = 0 ; i<n ; i++){ 
        string word = v[i]; 
        int flag = 0;
        for(int j = 0 ; j< word.length() ;j++){
            if(visited[word[j] - 'a'] == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){ 
            cnt++;
        }
    }
    return cnt;
}

void get_combination(int idx, int cnt){
    if(cnt == k - 5){ 
        answer = max(answer, get_word_cnt());
        return;
    }
    for(int i = idx ; i < MAX ; i++){ 
        if (alphabet[i] == 1 && visited[i] == 0){
            visited[i] = 1;
            get_combination(i, cnt + 1);
            visited[i] = 0;
        }
    }
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> n >> k;

    for(int i = 0 ; i< n ; i++){
        cin >> str;
        v.push_back(str);
    }

    
    if(k < 5){
        cout <<"0\n";
        return 0;
    }

    // 등장 단어 체크
    for(int i = 0 ; i< n ; i++){
        string word = v[i];
        for(int j =0 ; j< word.length() ; j++){
            alphabet[word[j]-'a'] = 1;
        }
    }

    int word_total_cnt = 0;

    for(int i = 0 ; i< 27 ; i++){
        if(alphabet[i] == 1){
            word_total_cnt++;
        }
    }

    // 단어를 모두 셀 수 있는 경우
    if(word_total_cnt <= k){
        cout << n << "\n";
        return 0;
    }

    visited['a' - 'a'] = 1;
    visited['n' - 'a'] = 1;
    visited['t' - 'a'] = 1;
    visited['i' - 'a'] = 1;
    visited['c' - 'a'] = 1;

    get_combination(0, 0);

    cout << answer << "\n";

    return 0;
}