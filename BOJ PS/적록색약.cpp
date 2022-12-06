//
//  적록색약.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/02.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
char field[105][105] = {0, };
char weakness_field[105][105] = {0, };
int visited[105][105] ={0, };
int colorWeaknessVisited[105][105] = {0, };
int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int normal_cnt = 0, color_weakness_cnt = 0;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char temp;
            cin>>temp;
            
            field[i][j] = temp;
            if(temp == 'G'){
                weakness_field[i][j] = 'R';
                continue;
            }
            weakness_field[i][j] = temp;
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0){
                normal_cnt++;
                char color = field[i][j];
                queue<pair<int, int> >q;
                q.push({i, j});
                
                while(!q.empty()){
                    int frontX = q.front().first;
                    int frontY = q.front().second;
                    
                    q.pop();
                    for(int i=0; i<4; i++){
                        int dx = frontX + nx[i];
                        int dy = frontY + ny[i];
                        
                        if(0<=dx && dx<n && 0<=dy && dy<n){
                            if(visited[dx][dy] != 0) continue;
                            if(color != field[dx][dy]) continue;
                            q.push({dx, dy});
                            visited[dx][dy] = normal_cnt;
                        }
                        
                    }
                }
                
            }
        }
    }
    
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            cout<<visited[i][j];
//        }
//        cout<<endl;
//    }
    cout<<normal_cnt<<" ";
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            if(colorWeaknessVisited[i][j] == 0){
                color_weakness_cnt++;
                char color = weakness_field[i][j];
                queue<pair<int, int> >q;
                q.push({i, j});
                
                while(!q.empty()){
                    int frontX = q.front().first;
                    int frontY = q.front().second;
                    
                    q.pop();
                    for(int i=0; i<4; i++){
                        int dx = frontX + nx[i];
                        int dy = frontY + ny[i];
                        
                        if(0<=dx && dx<n && 0<=dy && dy<n){
                            if(colorWeaknessVisited[dx][dy] != 0) continue;
                            if(color != weakness_field[dx][dy]) continue;
                            q.push({dx, dy});
                            colorWeaknessVisited[dx][dy] = color_weakness_cnt;
                        }
                        
                    }
                }
                
            }
        }
    }
    cout<<color_weakness_cnt;
    
    return 0;
}
