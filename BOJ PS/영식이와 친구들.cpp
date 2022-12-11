//
//  영식이와 친구들.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/08.
//

#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, l;
    int cnt = 1;
    cin>>n>>m>>l;
    deque<int> dq;
    dq.push_front(1);
    
    for(int i=1; i<n; i++){
        dq.push_back(0);
    }
    
    while(1){
        if(dq.front() == m) break;
        
        if(dq.front() % 2==1){
            for(int i=0; i<l; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.front() = dq.front()+1;
            cnt++;
        }
        
        else if(dq.front() % 2==0){
            for(int i=0; i<l; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.front() = dq.front()+1;
            cnt++;
        }
    }
    
    cout<<cnt-1;
    return 0;
}
