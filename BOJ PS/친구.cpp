//
//  친구.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/17.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int friendList[60][60];
vector<string> cmd;


void input(){
    cin>>n;
    
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        
        cmd.push_back(temp);
    }
}

void make_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                friendList[i][j] = 0;
                continue;
            }
            
            char now_char = cmd[i][j];
            if(now_char=='Y') {
                friendList[i][j] = 1;
            }
            else friendList[i][j] = 987654321;
            
        }
    }
}

void floyd(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j || i==k || j==k) continue;
                
                if(friendList[i][j] > friendList[i][k] + friendList[k][j]){
                    friendList[i][j] = friendList[i][k] + friendList[k][j];
                }
            }
        }
    }
}

void solve(){
    make_map();
    floyd();
    
    int ans = 0;
    for(int i=0; i<n; i++){
        int local_sum = 0;
        for(int j=0; j<n; j++){
            if(friendList[i][j] <= 2) local_sum += 1;
        }
        
        ans = max(ans, local_sum);
    }
    
    cout<<ans-1;
    return;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solve();
}
