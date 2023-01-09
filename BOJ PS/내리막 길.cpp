//
//  내리막 길.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/09.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int field[505][505];
int ans[505][505];

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>field[i][j];
        }
    }
    
    queue<pair<int, int> > q;
    q.push({0, 0});
    ans[0][0] = 1;
    
    while(!q.empty()){
        int frontX = q.front().first;
        int frontY = q.front().second;
        
        q.pop();
        for(int i=0; i<4; i++){
            int dx = frontX + nx[i];
            int dy = frontY + ny[i];
            
            if(0<=dx && dx < n && 0<=dy && dy < m){
                if(field[dx][dy] < field[frontX][frontY]){
                    ans[dx][dy]++;
                    q.push({dx, dy});
                }
            }
        }
    }
    
    cout<<ans[n-1][m-1];
    return 0;
}
