//
//  공주님을 구해라.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/07.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long field[200][200], visited[200][200], sword_visited[200][200];
int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};
int n, m, t;
int swordX = -10, swordY = -10;
int solution();
int swordSolution();

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    
    int normal=0, sword=0;
    cin>>n>>m>>t;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin>>temp;
            
            field[i][j] = temp;
        }
    }
    
    normal = solution();
//    cout<<normal<<"\n";
    if(swordX == -10 && swordY == -10){
        if(normal <=0) cout<<"Fail";
        else cout<<normal;
        return 0;
    }
    
    sword = swordSolution();
//    cout<<sword<<"\n";
    
    if(normal< 0 && sword < 0)cout << "Fail";
    else{
        int smaller = 10000;
        if(normal <=0) normal = 100000;
        if(sword <=0) sword = 1000000;
        normal < sword ? smaller = normal : smaller = sword;
        
        if(smaller <= t){
            cout<<smaller;
        }
        else{
            cout<<"Fail";
        }
    }
    return 0;
}

int solution(){
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = front.first + nx[i];
            int dy = front.second + ny[i];
            
            if(0 <= dx && dx < n && 0 <= dy && dy < m){
                if(field[dx][dy] == 1){
                    continue;
                }
                if(visited[dx][dy] == 0)
                {
                    if(field[dx][dy] == 2){
                        swordX = dx;
                        swordY = dy;
                    }
                    q.push({dx, dy});
                    visited[dx][dy] = visited[front.first][front.second] + 1;
                }
                
            }
        }
    }
    
//    cout<<"\n===========\n";
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout<<visited[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
    return visited[n-1][m-1] - 1;
}

int swordSolution(){
    queue<pair<int, int> > q;
    q.push({swordX, swordY});
    sword_visited[swordX][swordY] = visited[swordX][swordY];
    
    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int dx = front.first + nx[i];
            int dy = front.second + ny[i];
            
            if(0 <= dx && dx < n && 0 <= dy && dy < m){
                if(sword_visited[dx][dy] == 0)
                {
                    if(field[dx][dy] == 2){
                        swordX = dx;
                        swordY = dy;
                    }
                    q.push({dx, dy});
                    sword_visited[dx][dy] = sword_visited[front.first][front.second] + 1;
                }
                
            }
        }
    }
//    cout<<"\n===========\n";
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout<<sword_visited[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//    cout<<"\n===========\n";
    return sword_visited[n-1][m-1] - 1;
}
