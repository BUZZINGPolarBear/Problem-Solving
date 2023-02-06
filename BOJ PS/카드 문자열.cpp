//
//  카드 문자열.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/06.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

void solve(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        char temp;
        deque<char> dq;
        cin>>n;
        cin>>temp;
        
        dq.push_back(temp);
        
        for(int i=1; i<n; i++){
            cin>>temp;
            
            if(temp <= dq.front()) dq.push_front(temp);
            else dq.push_back(temp);
        }
        
        while(!dq.empty()){
            cout<<dq.front();
            dq.pop_front();
        }
        
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
