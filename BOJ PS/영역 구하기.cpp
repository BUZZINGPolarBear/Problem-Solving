//
//  영역 구하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/04.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int field[105][105], visited[105][105];
int ny[4] = {1, 0, -1, 0};
int nx[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int m, n, k;
    int island_cnt = 0;
    vector<int> ans;
    cin>>m>>n>>k;
    while(k--){
        int left_x, left_y, right_x, right_y;
        cin>>left_x>>left_y>>right_x>>right_y;
        
        for(int i=left_x; i<right_x; i++){
            for(int j=left_y; j<right_y; j++){
                field[i][j] = 1;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(field[i][j] == 0){
                island_cnt++;
                queue<pair<int, int> > q;
                q.push({i, j});
                int size = 1;
                visited[i][j] = size;
                
                while(!q.empty()){
                    int front_x = q.front().first;
                    int front_y = q.front().second;
                    
                    q.pop();
                    for(int i=0; i<4; i++){
                        int dx = front_x + nx[i];
                        int dy = front_y + ny[i];
                        
                        if(0<=dx && dx<n && 0<=dy && dy<m){
                            if(visited[dx][dy] != 0) continue;
                            if(field[dx][dy] == 1) continue;
                            
                            visited[dx][dy] = visited[front_x][front_y] + 1;
                            field[dx][dy] = 1;
                            size++;
                            q.push({dx, dy});
                        }
                    }
                }
                ans.push_back(size);
            }
           
        }
    }
    cout<<island_cnt<<"\n";
    sort(ans.begin(), ans.end());
//    for(int i=0; i<n; i++){
//        for(int j=0; j<m; j++){
//            cout<<visited[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<"=================\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
    
    return 0;
}
