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
int dp[505][505];

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int n, m;

void print_ans(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\n==========================\n";
}

int dp_find(int x, int y){
    if(x==n-1 && y==m-1){
        return 1;
    }
    
    if(dp[x][y] == -1){
        dp[x][y] = 0;
        for(int i=0; i<4; i++){
            int dx = x + nx[i];
            int dy = y + ny[i];
            if(0<=dx && dx < n && 0<=dy && dy < m){
                if(field[dx][dy] < field[x][y]){
                    dp[x][y] += dp_find(dx, dy);
                }
            }
        }
    }
    
    return dp[x][y];
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>field[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout<<dp_find(0, 0);
    return 0;
    
}
