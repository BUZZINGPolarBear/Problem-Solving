//
//  탈출.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/07.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
pair<int, int> goal;
char field[55][55];
int visited[55][55]={0, };
int animal_visited[55][55]={0, };
int r, c;
bool is_reached = false;
queue<pair<int, int> > water_q, animal_q;


void print_visited(int idx){
    cout<<"IDX: "<<idx<<"\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cout<<visited[i][j]<<" ";
        cout<<"\n";
    }
    
    cout<<"-------------\n";
}

void print_animal_visited(int idx){
    cout<<"IDX: "<<idx<<"\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cout<<animal_visited[i][j]<<" ";
        cout<<"\n";
    }
    
    cout<<"-------------\n";
}

void input(){
    cin>>r>>c;
    char temp;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>temp;
            field[i][j] = temp;
            if(temp == 'S') {
                animal_q.push({i, j});
                visited[i][j] = 1;
            }
            if(temp == '*') water_q.push({i, j});
            if(temp == 'D') goal = {i, j};
        }
    }
}

void bfs(){
    while(!animal_q.empty()){
        
        //물을 먼저 한칸 넓히기
        int water_size = water_q.size();
        for(int i=0; i<water_size; i++){
            int front_x = water_q.front().first;
            int front_y = water_q.front().second;
            
            water_q.pop();
            for(int i=0; i<4; i++){
                int nx = front_x + dx[i];
                int ny = front_y + dy[i];
                
                if(0<=nx && nx<r && 0<=ny && ny < c){
                    if(field[nx][ny] == '.'){
                        water_q.push({nx, ny});
                        field[nx][ny] = '*';
                    }
                }
            }
        }
        
        //고습도치 움직이기
        int animal_size = animal_q.size();
        for(int i=0; i<animal_size; i++){
            int front_x = animal_q.front().first;
            int front_y = animal_q.front().second;
            
            animal_q.pop();
            for(int i=0; i<4; i++){
                int nx = front_x + dx[i];
                int ny = front_y + dy[i];
                
                if(0<=nx && nx<r && 0<=ny && ny<c){
                    if((field[nx][ny] == '.' || field[nx][ny] == 'D') && visited[nx][ny] == 0){
                        animal_q.push({nx, ny});
                        visited[nx][ny] = visited[front_x][front_y] + 1;
                    }
                }
            }
        }
    }
}


void solve(){
    int idx = 1;

    bfs();
    
    
    if(visited[goal.first][goal.second] == 0){
        cout<<"KAKTUS";
    }
    else{
        cout<<visited[goal.first][goal.second]-1;
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solve();
}
