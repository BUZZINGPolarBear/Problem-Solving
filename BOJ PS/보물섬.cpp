//
//  보물섬.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/11.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};

int field[55][55];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int r, c;
    int ans = 0;
    
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char temp;
            cin>>temp;
            
            if(temp == 'W') field[i][j] = 0;
            else if(temp == 'L') field[i][j] = 1;
        }
    }
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(field[i][j] == 1){
                //새로운 섬 발견
                int visited[55][55] = {0, };
                queue<pair<int, int> > q;
                q.push({i, j});
                visited[i][j] = 1;
                
                int local_max = 1;
                
                while(!q.empty()){
                    int frontX = q.front().first;
                    int frontY = q.front().second;
                    
                    q.pop();
                    for(int k=0; k<4; k++){
                        int dx = frontX + nx[k];
                        int dy = frontY + ny[k];
                        
                        if(0<=dx && dx< r && 0<=dy && dy< c){
                            if(visited[dx][dy] != 0) continue;
                            if(field[dx][dy] == 0) continue;
                            visited[dx][dy] = visited[frontX][frontY]+1;
                            q.push({dx, dy});
                            
                            if(local_max < visited[dx][dy]) local_max = visited[dx][dy];
                        }
                    }
                }
                if(ans < local_max) ans = local_max;
            }
        }
    }

    cout<<ans-1;
    return 0;
}
