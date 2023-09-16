#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    // 다 2배 늘려주기
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    // 그래프도 2배 늘리기
    for(int i = 0 ; i<rectangle.size() ; i++){
        for(int j = 0 ; j < 4 ; j++){
            rectangle[i][j] *= 2;
        }
    }
    
    vector<vector<int>> graph(102, vector<int>(102, 0));
    
    for(int i = 0 ; i < rectangle.size() ; i++){
        vector<int> cur = rectangle[i]; 
        for(int r = cur[0]; r <= cur[2] ; r++){
            for(int c = cur[1] ; c <= cur[3] ; c++){
                graph[r][c] = 2;
            }
        }
    }

    // 속 파내기
    for(int i = 0 ; i < rectangle.size() ; i++){
        vector<int> cur = rectangle[i]; 
        for(int r = cur[0] + 1; r < cur[2] ; r++){
            for(int c = cur[1] + 1 ; c <cur[3] ; c++){
                    graph[r][c] = 1;
            }
        }
    }
    
    
    
    queue<tuple<int, int, int>> q; // 좌표 저장
    q.push(make_tuple(characterX, characterY, 0));
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int visited[102][102] = {0};
    visited[characterX][characterY] = 1;
    
    int cnt = 0;
    
    while(1){
        tuple<int, int, int> cur = q.front();
        cnt = get<2>(cur);
        q.pop();
        
        if(get<0>(cur) == itemX && get<1>(cur) == itemY) break;
        
        for(int i = 0 ; i< 4 ; i++){
            int nx = get<0>(cur) + dx[i];
            int ny = get<1>(cur) + dy[i];
            
            if(nx >= 0 && nx <= 101 && ny >= 0 && ny <= 101 && visited[nx][ny] == 0 && graph[nx][ny] == 2){
                visited[nx][ny] = 1;
                q.push(make_tuple(nx, ny, cnt + 1));
            }
        }   
    }
    
    return cnt / 2;
    
}