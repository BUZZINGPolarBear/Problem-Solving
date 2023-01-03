//
//  로봇 청소기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int field[60][60];
int visited[60][60];
int n, m;
int r, c, d;
int ans=0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void print(int n, int m){
    cout<<"\n=========================\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void dfs()
{
//    print(n, m);
    for(int i=0; i<4; i++){
        int next_direction = (d+3 - i) % 4;
        
        int next_r = r + dx[next_direction];
        int next_c = c + dy[next_direction];
        
        if(next_r <0 || next_r >= n || next_c < 0 || next_c >= m || field[next_r][next_c] == 1) continue;
        
        if(field[next_r][next_c]==0 && visited[next_r][next_c]==0){
            visited[next_r][next_c] = 1;
            r = next_r;
            c = next_c;
            d = next_direction;
            ans++;
            dfs();
        }
    }
    
    int back_idx = d > 1 ? d-2 : d+2;
    int back_r = r + dx[back_idx];
    int back_c = c + dy[back_idx];
    
    if(back_r >= 0 && back_r <= n && back_c >= 0 && back_c < m){
        if(field[back_r][back_c] == 0){
            r = back_r;
            c = back_c;
            dfs();
        }
        else{
            cout<<ans;
            exit(0);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    cin>>r>>c>>d;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>field[i][j];
        }
    }
    visited[r][c]=1;
    ans++;
    dfs();
    return 0;
}
