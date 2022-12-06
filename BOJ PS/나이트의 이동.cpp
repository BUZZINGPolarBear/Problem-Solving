//
//  나이트의 이동.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/02.
//

#include <iostream>
#include <queue>
using namespace std;
int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ny[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        int l;
        int firstX, firstY;
        int objectX, objectY;
        queue<pair<int, int> > q;
        cin>>l;
        cin>>firstX>>firstY;
        cin>>objectX>>objectY;
        
        int visited[305][305] = {0, };
        q.push({firstX, firstY});
        visited[firstX][firstY] = 1;
        
        while(!q.empty()){
            int frontX = q.front().first;
            int frontY = q.front().second;
            if(frontX == objectX && frontY == objectY){
                cout<<visited[frontX][frontY]-1<<"\n";
                break;
            }
            q.pop();
            
            for(int i=0; i<8; i++){
                int dx = frontX + nx[i];
                int dy = frontY + ny[i];
                
                if(0<=dx && dx<l && 0<=dy && dy<l){
                    if(visited[dx][dy] != 0) continue;
                    visited[dx][dy] = visited[frontX][frontY] + 1;
                    q.push({dx, dy});
                }
                
            }
        }
    }
}
