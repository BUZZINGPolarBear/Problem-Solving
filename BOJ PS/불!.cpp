//
//  불!.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/01.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char field[1005][1005]={0,};
int fireVisited[1005][1005]={0,};
int humanVisited[1005][1005]={0,};
int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int main(){
    int r, c;
    queue<pair<int, int> > humanQ, fireQ;
    
    cin>>r>>c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char temp;
            cin>>temp;
            
            if(temp == 'F'){
                fireQ.push({i, j});
                fireVisited[i][j] = 1;
            }
            if(temp == 'J')
            {
                humanQ.push({i, j});
                if(i==0 || j==0){
                    cout<<1;
                    return 0;
                }
                if(i==r-1 || j==c-1){
                    cout<<1;
                    return 0;
                }
            }
            field[i][j] = temp;
        }
    }
    
    humanVisited[humanQ.front().first][humanQ.front().second] = 1;
    
    while(!humanQ.empty()){
        int nowX = humanQ.front().first;
        int nowY = humanQ.front().second;
        
        humanQ.pop();
        for(int i=0; i<4; i++){
            int dx = nowX + nx[i];
            int dy = nowY + ny[i];
            
            if(field[dx][dy] == '#')continue;
            if(0<=dx && dx<r && 0<=dy && dy<c){
                if(humanVisited[dx][dy] != 0) continue;
                
                humanVisited[dx][dy] = humanVisited[nowX][nowY] + 1;
                humanQ.push({dx, dy});
            }
        }
    }
    
//    cout<<"=====================\n";
//    for(int i=0; i<r; i++){
//        for(int j=0; j<c; j++){
//            cout<<humanVisited[i][j];
//        }
//        cout<<endl;
//    }
//
    if(fireQ.empty()){
        int min = 100000;
        for(int i=0; i<r; i++){
            if(humanVisited[i][0] < min){
                if(humanVisited[i][0] != 0) min = humanVisited[i][0];
            }
            if(humanVisited[i][c-1] < min){
                if(humanVisited[i][c-1] != 0) min = humanVisited[i][c-1];
            }
        }
        
        for(int i=0; i<c; i++){
            if(humanVisited[0][i] < min){
                if(humanVisited[0][i] != 0) min = humanVisited[0][i];
            }
            if(humanVisited[r-1][i] < min){
                if(humanVisited[r-1][i] != 0) min = humanVisited[r-1][i];
            }
        }
        if(min == 100000) cout<<"IMPOSSIBLE";
        else cout<<min;
        return 0;
    }
    while(!fireQ.empty()){
        int nowX = fireQ.front().first;
        int nowY = fireQ.front().second;
        
        fireQ.pop();
        for(int i=0; i<4; i++){
            int dx = nowX + nx[i];
            int dy = nowY + ny[i];
            
            if(field[dx][dy] == '#') continue;
            if(0<=dx && dx < r && 0<=dy && dy <c){
                if(fireVisited[dx][dy] != 0) continue;
                
                fireQ.push({dx, dy});
                fireVisited[dx][dy] = fireVisited[nowX][nowY] + 1;
            }
        }
    }
    
//    for(int i=0; i<r; i++){
//        for(int j=0; j<c; j++){
//            cout<<fireVisited[i][j];
//        }
//        cout<<endl;
//    }
    
    int min = 100000;
    for(int i=0; i<r; i++){
        if(humanVisited[i][0] < fireVisited[i][0]){
            if(humanVisited[i][0] < min) min = humanVisited[i][0];
        }
        if(humanVisited[i][c-1] < fireVisited[i][c-1]){
            if(humanVisited[i][c-1] < min) min = humanVisited[i][c-1];
        }
    }
    
    for(int i=0; i<c; i++){
        if(humanVisited[0][i] < fireVisited[0][i]){
            if(humanVisited[0][i] < min) min = humanVisited[0][i];
        }
        if(humanVisited[r-1][i] < fireVisited[r-1][i]){
            if(humanVisited[r-1][i] < min) min = humanVisited[r-1][i];
        }
    }
    
    if(min == 100000) cout<<"IMPOSSIBLE";
    else cout<<min;
    
    return 0;
}
