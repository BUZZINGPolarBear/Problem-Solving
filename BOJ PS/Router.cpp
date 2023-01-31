//
//  Router.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/31.
//

#include <iostream>
#include <queue>
using namespace std;
int n;


void solve(){
    cin>>n;
    queue<int> q;
    
    while(1){
        int temp;
        cin>>temp;
        
        if(temp == -1) break;
        
        if(temp == 0) q.pop();
        else{
            if(q.size() < n) q.push(temp);
        }
    }
    
    if(q.empty()) cout<<"empty";
    else{
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
