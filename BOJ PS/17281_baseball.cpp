//
//  17281_baseball.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n;
vector<vector<pair<int, int> > > inning(80);
int play_ball(vector<int> player_idx){
    vector<int>::iterator iter = player_idx.begin();
    iter = player_idx.insert(iter, 0);
    iter = player_idx.insert(iter+4, 1);
    
    deque<int> now_base;
    int out_cnt = 0;

    int score = 0;
    int now_inning = 1;
    int now_player = 0;
    while(now_inning <= n){
        while(out_cnt < 3){
            now_player %= 9;
            now_player++;
            int base = inning[now_inning][player_idx[now_player]].second;
            if(base == 0) {
                out_cnt++;
            }
            else{
                if(base==1){
                    now_base.push_front(1);
                    while(now_base.size() > 3){
                        score += now_base.back();
                        now_base.pop_back();
                    }
                }
                else if(base==2){
                    now_base.push_front(1);
                    now_base.push_front(0);
                    while(now_base.size() > 3){
                        score += now_base.back();
                        now_base.pop_back();
                    }
                }
                else if(base==3){
                    now_base.push_front(1);
                    now_base.push_front(0);
                    now_base.push_front(0);
                    while(now_base.size() > 3){
                        score += now_base.back();
                        now_base.pop_back();
                    }
                }
                else if(base==4){
                    while(!now_base.empty()){
                        score += now_base.back();
                        now_base.pop_back();
                    }
                    score++;
                }
            }
        }
        now_inning++;
        out_cnt=0;
        while(!now_base.empty()) now_base.pop_back();
    }
    
    return score;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        inning[i].push_back({-100, -100});
        for(int j=1; j<=9; j++){
            int temp;
            cin>>temp;
            inning[i].push_back({j, temp});
        }
    }
    
    int ans = -1000;
    vector<int> player_idx = {2, 3, 4, 5, 6, 7, 8, 9};
    do{        
        int temp = play_ball(player_idx);
        ans < temp ? ans = temp : ans;
    }while(next_permutation(player_idx.begin(), player_idx.end()));
    
    cout<<ans;
    return 0;
}
