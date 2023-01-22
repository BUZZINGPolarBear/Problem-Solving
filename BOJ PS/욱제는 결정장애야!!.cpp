//
//  욱제는 결정장애야!!.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/21.
//

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = -100;
deque<int> result_dq;
vector<int> all_v;

void input(){
    cin>>n;
    
    for(int i=0; i<2*n; i++){
        int temp;
        cin>>temp;
        
        result_dq.push_back(temp);
    }
    
    for(int i=1; i<=n+1; i++) all_v.push_back(0);
}

void get_ans(){
    int local_ans=0;
    for(int i=0; i<result_dq.size(); i++){
        if(all_v[result_dq[i]] == 0){
            local_ans++;
            all_v[result_dq[i]] = 1;
        }
        else if(all_v[result_dq[i]] == 1){
            local_ans--;
            all_v[result_dq[i] = 2];
        }
        else if(all_v[result_dq[i]] == 2) continue;
        
        ans = max(ans, local_ans);
    }
}
void solve(){
    input();
    get_ans();
    cout<<ans;
    
    return;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    
    return 0;
}

