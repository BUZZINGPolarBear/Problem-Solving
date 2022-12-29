//
//  컴백홈.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/29.
//

#include <iostream>
#include <vector>
using namespace std;

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int visited[6][6];
char field[6][6];
int r, c, k;
int ans = 0;

void dfs(int x, int y, int cnt){   
    if(cnt == k && x == 0 && y == c-1){
        ans++;
        return;
    }
    for(int i=0; i<4; i++){
        int dx = x + nx[i];
        int dy = y + ny[i];
        
        if(0<=dx && dx<r && 0<=dy && dy < c){
            if(field[dx][dy] == 'T') continue;
            if(visited[dx][dy] == 1) continue;
            
            visited[dx][dy] = 1;
            dfs(dx, dy, cnt + 1);
            visited[dx][dy] = 0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>r>>c>>k;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char temp;
            cin >> temp;
            field[i][j] = temp;
        }
    }
    
    visited[r-1][0] = 1;
    dfs(r-1, 0, 1);
    cout<<ans;
    return 0;
}
