//
//  톱니바퀴.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/25.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

deque<int> dq1, dq2, dq3, dq4;
vector<pair<int, int> > cmd;
int k;

void input(){
    string temp;
    
    cin>>temp;
    for(int j=0; j<8; j++) dq1.push_back(temp[j] - '0');
    cin>>temp;
    for(int j=0; j<8; j++) dq2.push_back(temp[j] - '0');
    cin>>temp;
    for(int j=0; j<8; j++) dq3.push_back(temp[j] - '0');
    cin>>temp;
    for(int j=0; j<8; j++) dq4.push_back(temp[j] - '0');
    
    cin>>k;
    
    for(int i=0; i<k; i++){
        int a, b;
        cin>>a>>b;
        
        cmd.push_back({a, b});
    }
}

void make_turn(int idx){
    int dq_idx = cmd[idx].first;
    int turn_dir = cmd[idx].second;
    
    switch (dq_idx) {
        case 1:
            if(turn_dir==1){dq1.push_front(dq1.back()); dq1.pop_back();}
            else {dq1.push_back(dq1.front()); dq1.pop_front();}
            break;
            
        case 2:
            if(turn_dir==1){dq2.push_front(dq2.back()); dq2.pop_back();}
            else {dq2.push_back(dq2.front()); dq2.pop_front()};
            break;
            
        case 3:
            if(turn_dir==1){dq3.push_front(dq3.back()); dq3.pop_back();}
            else {dq3.push_back(dq3.front()); dq3.pop_front();}
            break;
        
        case 4:
            if(turn_dir==1){dq4.push_front(dq4.back()); dq4.pop_back();}
            else {dq4.push_back(dq4.front()); dq4.pop_front();}
            break;
    }
}

void second_turn(int idx){
    int dq_idx = cmd[idx].first;
    int turn_dir = cmd[idx].second;
    
    switch(dq_idx){
        case 1:
            if(dq1[2] == )
    }
}
void solve(){
    input();
    for(int i=0; i<k; i++){
        make_turn(i);
        second_turn(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    
    return 0;
}

