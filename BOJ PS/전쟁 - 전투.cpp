//
//  전쟁 - 전투.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/06.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int field[105][105];
int visited[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void input(){
    cin>>n>>m;
    char temp;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>temp;
            temp == 'W' ? field[i][j] = 0 : field[i][j] = 1;
        }
    }
}

long long bfs(int x, int y, int anchor){
    queue<pair<int, int> > q;
    long long cnt = 1;
    q.push({x, y});
    visited[x][y] = 1;
    
    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++){
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];
            
            if(0 <= nx && nx < m && 0 <= ny && ny < n ){
                if(visited[nx][ny] == 0){
                    if(field[nx][ny] == anchor){
                        cnt++;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
//    cout<<cnt<<endl;
    return cnt*cnt;
}

void solve(){
    input();
    
    long long W_cnt = 0, B_cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(field[i][j] == 0 && visited[i][j] == 0){
                W_cnt += bfs(i, j, 0);
            }
            else if(field[i][j] == 1 && visited[i][j] == 0){
                B_cnt += bfs(i, j, 1);
            }
        }
    }
    
    cout<<W_cnt<<" "<<B_cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();

}
