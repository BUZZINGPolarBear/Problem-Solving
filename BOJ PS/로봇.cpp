//
//  로봇.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char watch = 'e';
int m, n;
pair<int, int> now_dir;
vector<pair<string, int> > cmd;


void input(){
    cin>>m>>n;
    
    for(int i=0; i<n; i++){
        string str;
        int go;
        
        cin>>str>>go;
        
        cmd.push_back({str, go});
    }
}

void follow_cmd(int cmd_idx){
    string first = cmd[cmd_idx].first;
    int second = cmd[cmd_idx].second;
    
    if(first == "MOVE"){
        if(watch == 'e'){
            now_dir.second += second;
        }
        else if(watch == 's'){
            now_dir.first -= second;
        }
        else if(watch == 'w'){
            now_dir.second -= second;
        }
        else if(watch == 'n'){
            now_dir.first += second;
        }
    }
    else{
        if(second == 0){
            if(watch=='e') watch = 'n';
            else if(watch=='n') watch = 'w';
            else if(watch=='w') watch = 's';
            else if(watch=='s') watch = 'e';
        }
        else if(second == 1){
            if(watch=='e') watch = 's';
            else if(watch=='n') watch = 'e';
            else if(watch=='w') watch = 'n';
            else if(watch=='s') watch = 'w';
        }
    }
}

void check(){
    if(0<=now_dir.first && now_dir.first < m && 0<=now_dir.second && now_dir.second < m){
        cout<<now_dir.second << " "<<now_dir.first;
    }
    else cout<<-1;
}
void solve(){
    input();
    for(int i=0; i<n; i++){
        follow_cmd(i);
        if(now_dir.first < 0 || m <= now_dir.first || now_dir.second < 0 || m <= now_dir.second){
            cout<<-1;
            return;
        }
    }
    
    cout<<now_dir.second << " "<<now_dir.first;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    
    return 0;
}
