#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int r, c, k;
int arr[101][101]; 

struct compare{
    // 등장횟수가 작은게 우선순위
    bool operator()(pair<int, int> & p1, pair<int, int> &p2){
        if(p1.first == p2.first){
            return p1.second < p2.second ? false : true;
        // 숫자가 작은게 우선순위
        } return p1.first < p2.first ? false : true;
    }
};
int main(void){

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j< 3 ; j++){
            cin >> arr[i][j];
        }
    }
    int time = 0;

    int cur_r = 3, cur_c = 3;

    while(arr[r-1][c-1] != k && time <= 100){
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        int new_arr[101][101] = {0};
        int max_r = 0, max_c = 0;
        if(cur_r >= cur_c){
            for(int i = 0 ; i < cur_r ; i++){
                map<int, int> m;
                for(int j = 0 ; j < cur_c ; j++){
                    if(arr[i][j] == 0) continue;
                    m[arr[i][j]]++;
                }
                // map->pq로 옮기기
                for(auto &cell :m) pq.push({cell.second, cell.first}); // 숫자, 등장 횟수
                
                int fill_idx = 0; // 0번부터 채워넣기
                while(!pq.empty() && fill_idx < 100){
                    pair<int, int> cur = pq.top();
                    pq.pop();
                    new_arr[i][fill_idx++] = cur.second;
                    if(fill_idx == 100) break;
                    new_arr[i][fill_idx++] = cur.first;
                }
                max_c = max(max_c, fill_idx); // 최댓값 갱신
            }
        } else {
            while(!pq.empty()) pq.pop();

            for(int i = 0 ; i < cur_c ; i++){ // 
                map<int, int> m;
                for(int j = 0 ; j < cur_r ; j++){
                    if(arr[j][i] == 0) continue; 
                    m[arr[j][i]]++;
                }
                for(auto &cell :m) pq.push({cell.second, cell.first});
                
                int fill_idx = 0; // 0번부터 채워넣기
                while(!pq.empty() && fill_idx < 100){
                    pair<int, int> cur = pq.top();
                    pq.pop();
                    new_arr[fill_idx++][i] = cur.second;
                    if(fill_idx == 100) break; 
                    new_arr[fill_idx++][i] = cur.first;
                }
                max_r = max(max_r, fill_idx);
            }
        }

        cur_r = max(max_r, cur_r);
        cur_c = max(max_c, cur_c);
        
        // new_arr => arr 복사
        for(int i = 0 ; i < 100 ; i++){
            for(int j = 0 ; j< 100 ; j++){
                arr[i][j] = new_arr[i][j];
            }
        }
        time++;
    }
    
    if(time > 100){
        cout << "-1\n";
    } else cout << time << "\n";


    return 0;
}