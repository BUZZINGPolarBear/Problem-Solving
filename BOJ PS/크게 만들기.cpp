//
//  크게 만들기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/24.
//

#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
deque<int> dq;
string inpt_str;
int cnt = 0;

void input(){
    cin>>n>>k;
    cin>>inpt_str;
}

void find_ans(){
    

    for(int i=0; i<n; i++){
        int now_num = inpt_str[i] - '0';
        while(dq.empty() == false && dq.back() < now_num){
            if(cnt >= k) break;
            dq.pop_back();
            cnt++;
        }
        dq.push_back(now_num);
    }
}

void print_ans(){
    for(int i=0; i<dq.size()-k+cnt; i++){
        cout<<dq[i];
    }
}
void solve(){
    input();
    
    find_ans();
    print_ans();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
