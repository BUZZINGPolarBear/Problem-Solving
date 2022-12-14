//
//  양 한마리... 양 두마리....cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/14.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        int h, w;
        char field[105][105] ={0, };
        int visited[105][105] ={0, };
        int ans = 0;
        cin>>h>>w;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                char temp;
                cin>>temp;
                
                field[i][j] = temp;
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(field[i][j] == '#' && visited[i][j] == 0){
                    ans++;
                    queue<pair<int, int> > q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    
                    while(!q.empty()){
                        int frontX = q.front().first;
                        int frontY = q.front().second;
                        
                        q.pop();
                        for(int i=0; i<4; i++){
                            int dx = frontX + nx[i];
                            int dy = frontY + ny[i];
                            
                            if(0<= dx && dx < h && 0 <= dy && dy < w){
                                if(field[dx][dy] == '.') continue;
                                if(visited[dx][dy] != 0) continue;
                                
                                q.push({dx, dy});
                                visited[dx][dy] = 1;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
