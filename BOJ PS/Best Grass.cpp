//
//  Best Grass.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/29.
//

#include <iostream>
using namespace std;

char field[105][105];
int visited[105][105];
int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int r, c;

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int dx = x + nx[i];
        int dy = y + ny[i];
        
        if(0<=dx && dx < r && 0<=dy && dy<c){
            if(field[dx][dy] == '.') continue;
            if(visited[dx][dy] != 0) continue;
            
            visited[dx][dy] = 1;
            dfs(dx, dy);
        }
    }
}

int main(){
    using namespace std; cin.tie(0); cout.tie(0);
    
    int ans=0;
    cin>>r>>c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char temp;
            cin>>temp;
            field[i][j] = temp;
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(field[i][j] == '#' && visited[i][j] == 0)
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    
    cout<<ans;
    return 0;
}
