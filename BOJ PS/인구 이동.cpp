//
//  인구 이동.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;

int n;
int l, r;
int avg_all_human=0;
int day=0;

int field[55][55] = {0, };
int visited[55][55] = {0, };
int open_field[55][55] = {0, };

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print_field(int idx){
    cout<<"\n ----- "<<idx<<"번 째 변화 -----\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<field[i][j]<<" ";
        cout<<endl;
    }
}
void print_open_field(int idx){
    cout<<"\n "<<idx<<"번 째 OPEN -----\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<open_field[i][j]<<" ";
        cout<<endl;
    }
}

void input(){
    cin>>n;
    cin>>l>>r;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>field[i][j];
            avg_all_human += field[i][j];
        }
    }
    avg_all_human /= n*n;
}

void clear_visited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)visited[i][j] = 0;
    }
}
void clear_open_field(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)open_field[i][j] = 0;
    }
}

bool find_open_border(){
    bool is_end = false;
    
    int open_border_cnt = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            queue<pair<int, int> > q;
            deque<pair<int, int> > dq;
            
            q.push({i, j});
            dq.push_front({i, j});
            visited[i][j] = 1;
            int isle_sum = field[i][j];
            
            while(!q.empty()){
                int front_x = q.front().first;
                int front_y = q.front().second;
                
                q.pop();
                for(int k=0; k<4; k++){
                    int nx = front_x + dx[k];
                    int ny = front_y + dy[k];
                    
                    if(0<=nx && nx<n && 0<=ny && ny<n){
                        if(visited[nx][ny] != 0) continue;
                        int difference = abs(field[front_x][front_y]-field[nx][ny]);
                        if(l<= difference && difference <= r){
                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                            dq.push_back({nx, ny});
                            isle_sum += field[nx][ny];
                        }
                    }
                }
            }
            
            if(dq.size() > 1) open_border_cnt++;
            
            if(dq.size() == 1){
                dq.pop_front();
                continue;
            }
            int avg = isle_sum / dq.size();
            while(!dq.empty()){
                field[dq.front().first][dq.front().second] = avg;
                dq.pop_front();
            }
        }
    }
    
    if(open_border_cnt == 1) return true;
    else return false;
}

void solve(){
    input();
    
    int stage = 1;
    while(1){
        bool is_not_found = find_open_border();
        if(is_not_found){
            cout<<day;
            break;
        }
//        print_open_field(stage);
//        bfs();
        day++;
        print_field(stage++);
        clear_visited();
        clear_open_field();
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    solve();
    
    return 0;
}
