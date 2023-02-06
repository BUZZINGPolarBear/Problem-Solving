//
//  숫자 할리갈리 게임.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/01.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
deque<int> dodo, suyeon;
deque<int> dodo_ground, suyeon_ground;


void input(){
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        int dodo_card, suyeon_card;
        cin >> dodo_card >> suyeon_card;
        
        dodo.push_back(dodo_card);
        suyeon.push_back(suyeon_card);
    }
}

void merge_dodo_into_suyeon(){
    while(!dodo_ground.empty()){
        suyeon.push_front(dodo_ground.back());
        dodo_ground.pop_back();
    }
    
    while(!suyeon_ground.empty()){
        suyeon.push_front(suyeon_ground.back());
        suyeon_ground.pop_back();
    }
}

void merge_suyeon_into_dodo(){
    while(!suyeon_ground.empty()){
        dodo.push_front(suyeon_ground.back());
        suyeon_ground.pop_back();
    }
    
    while(!dodo_ground.empty()){
        dodo.push_front(dodo_ground.back());
        dodo_ground.pop_back();
    }
}



bool play_game(int idx){
    bool is_end = false;
    if(idx %2 == 0 ){
        //도도 차례
        dodo_ground.push_back(dodo.back());
        dodo.pop_back();
        
        if(dodo.size()==0){
            cout<<"su";
            return true;
        }
    }
    else{
        //수연 차례
        suyeon_ground.push_back(suyeon.back());
        suyeon.pop_back();
        
        if(suyeon.empty()==true){
            cout<<"do";
            return true;
        }
    }
    
    //숫자 합 5 검사
    if(suyeon_ground.empty() == false && dodo_ground.empty() == false){
        if(dodo_ground.back() + suyeon_ground.back() == 5){
            //수연 승
            merge_dodo_into_suyeon();
        }
    }
    
    if(!dodo_ground.empty() && dodo_ground.back() == 5){
        //도도 승
        merge_suyeon_into_dodo();
    }
    else if(!suyeon_ground.empty() && suyeon_ground.back() == 5){
        //도도 승
        merge_suyeon_into_dodo();
    }
    
    
    return is_end;
}

void solve(){
    input();
    
    for(int i=0; i<m; i++){
        if(play_game(i)) return;
    }
    
    if(dodo.size() < suyeon.size()) cout<<"su";
    else if(dodo.size() > suyeon.size()) cout<<"do";
    else cout<<"dosu";
    return;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
