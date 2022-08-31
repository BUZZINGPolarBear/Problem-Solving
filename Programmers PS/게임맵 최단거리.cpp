//
//  게임맵 최단거리.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/31.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] ={-1, 1, 0, 0};
int dy[4] ={0, 0, -1, 1};
int visited[105][105];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int, int> > q;
    
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = currentX + dx[i];
            int ny = currentY + dy[i];
            
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(maps[nx][ny]==0) continue;
                if(visited[nx][ny] == 0){
                    q.push({nx, ny});
                    visited[nx][ny] = visited[currentX][currentY] + 1;
                }
            }
        }
    }
    
    if(visited[n-1][m-1] == 0) return -1;
    else  return visited[n-1][m-1];
}

int main(){
    cout<<solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}});
    
    return 0;
}
