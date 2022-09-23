//
//  장군.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/21.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//가로 10칸, 세로 9칸
int visited[15][15];
int dx[8] = {-3, -3, 3, 3, -2, 2, -2, 2};
int dy[8] = {-2, 2, -2, 2, 3, 3, -3, -3};

int main(){
    queue<pair<int, int> > q;
    int r1, c1, r2, c2;
    
    cin>>r1>>c1>>r2>>c2;
    
    q.push({r1, c1});
    visited[r1][c1] = 1;
    while(!q.empty()){
        pair<int, int> front = q.front();
        
        q.pop();
        for(int i=0; i<8; i++){
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];
            
            if(0<=nx && nx<=9 && 0<=ny && ny<=8){
                if(visited[nx][ny] == 0){
                    switch (i) {
                        case 0:
                            //상-좌
                            if((r2 == front.first -1 && c2 == front.second) || (r2 == front.first -2 && c2 == front.second-1)) continue;
                            break;
                        case 1:
                            //상-우
                            if((r2 == front.first -1 && c2 == front.second) || (r2 == front.first -2 && c2 == front.second+1)) continue;
                            break;
                        case 2:
                            //하-좌
                            if((r2 == front.first +1 && c2 == front.second) || (r2 == front.first +2 && c2 == front.second-1)) continue;
                            break;
                        case 3:
                            //하-우
                            if((r2 == front.first +1 && c2 == front.second) || (r2 == front.first +2 && c2 == front.second+1)) continue;
                            break;
                        case 4:
                            //우-상
                            if((r2 == front.first && c2 == front.second+1) || (r2 == front.first -1 && c2 == front.second+2)) continue;
                            break;
                        case 5:
                            //우-하
                            if((r2 == front.first && c2 == front.second+1) || (r2 == front.first +1 && c2 == front.second+2)) continue;
                            break;
                        case 6:
                            //좌-상
                            if((r2 == front.first && c2 == front.second-1) || (r2 == front.first -1 && c2 == front.second-2)) continue;
                            break;
                        case 7:
                            //좌-하
                            if((r2 == front.first && c2 == front.second-1) || (r2 == front.first +1 && c2 == front.second-2)) continue;
                            break;
                        default:
                            break;
                    }
                    visited[nx][ny] = visited[front.first][front.second] + 1;
                    
                    
                    q.push({nx, ny});
                }
            }
        }
        
    }
    if(visited[r2][c2] != 0)  cout<< visited[r2][c2]-1;
    else cout<<-1;
    return 0;
}
