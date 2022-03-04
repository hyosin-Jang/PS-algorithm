#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int size = triangle.size();
    for(int i =1 ; i<size ; i++){
        for(int j=0 ; j<=i ; j++){
            if(j==0)
                triangle[i][j] += triangle[i-1][j];
            else if (j==i)
                triangle[i][j] += triangle[i-1][j-1]; 
            else
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);  
        }  
    }
    
    for(int i=0 ; i<size ; i++)
        answer = max(answer, triangle[size-1][i]);
    
    return answer;
}
