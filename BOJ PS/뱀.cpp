//
//  뱀.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/13.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int nLX = -1;
int nLY = 0;

int nRX = 1;
int nRY = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int field[105][105] = {0, };
    int n, k, l;
    int nowX = 1, nowY = 1;
    int length = 1;
    int time = 0;
    char heading = 'R';
    vector<pair<int, char> > v;
    deque<pair<int, int> > snake;
    //n: 보드 크기 k: 사과의 갯수
    cin>>n>>k;
    for(int i=0; i<k; i++){
        int x, y;
        cin>>x>>y;
        
        field[x][y] = 2;
    }
    
    cin>>l;
    for(int i=0; i<l; i++){
        int x;
        char c;
        cin>>x>>c;
        
        v.push_back({x, c});
    }
    snake.push_front({1, 1});
    field[1][1] = 1;
    
//    cout<<"=============================\n";
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=n; j++) cout<<field[i][j]<<" ";
//        cout<<"\n";
//    }
    
    while(1){
        int dx, dy;
        if(v.size() > 0 && v[0].first == time){
            if(v[0].second == 'D'){
                if(heading == 'R'){
                    dx = nowX + 1;
                    dy = nowY;
                    heading = 'D';
                }
                else if(heading == 'D'){
                    dx = nowX;
                    dy = nowY - 1;
                    heading = 'L';
                }
                else if(heading == 'L'){
                    dx = nowX - 1;
                    dy = nowY;
                    heading = 'U';
                }
                else if(heading == 'U'){
                    dx = nowX;
                    dy = nowY + 1;
                    heading = 'R';
                }
            }
            
            else if(v[0].second == 'L'){
                if(heading == 'R'){
                    dx = nowX - 1;
                    dy = nowY;
                    heading = 'U';
                }
                else if(heading == 'D'){
                    dx = nowX;
                    dy = nowY + 1;
                    heading = 'R';
                }
                else if(heading == 'L'){
                    dx = nowX + 1;
                    dy = nowY;
                    heading = 'D';
                }
                else if(heading == 'U'){
                    dx = nowX;
                    dy = nowY - 1;
                    heading = 'L';
                }
            }
            v.erase(v.begin());
        }
        else{
            //입력이 없는 경우
            
            if(heading == 'R'){
                dx = nowX;
                dy = nowY + 1;
            }
            else if(heading == 'D'){
                dx = nowX + 1;
                dy = nowY;
            }
            else if(heading == 'L'){
                dx = nowX;
                dy = nowY - 1;
            }
            else if(heading == 'U'){
                dx = nowX - 1;
                dy = nowY;
            }
            
        }
        
        if(0<dx && dx <= n && 0 < dy && dy <= n){
            time++;
            if(field[dx][dy] == 0){
                //아무것도 없음.
                field[dx][dy] = 1;
                snake.push_back({dx, dy});
                field[snake.front().first][snake.front().second] = 0;
                snake.pop_front();
            }
            else if(field[dx][dy] == 1){
                time--;
                break;
            }
            
            else if(field[dx][dy] == 2){
                //사과
                field[dx][dy] = 1;
                snake.push_back({dx, dy});
            }
            
            nowX = dx;
            nowY = dy;
        }
        
        else{
            break;
        }
        
//        cout<<"=============================\n";
//        cout<<"TIME: "<<time<<endl;
//        cout<<"COMMEND: "<< v[0].first <<", " <<v[0].second<<endl;
//        for(int i=1; i<=n; i++){
//            for(int j=1; j<=n; j++) cout<<field[i][j]<<" ";
//            cout<<"\n";
//        }
    }
    
    cout<<time+1;
    return 0;
}
