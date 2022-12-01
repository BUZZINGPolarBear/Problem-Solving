//
//  아이들과 선물 상자.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/18.
//

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    vector<int> v;
    priority_queue<int> q;
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }
    
    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    for(int i=0; i<m; i++){
        if(q.top() < v[i]){
            cout<<0;
            return 0;
        }
        else{
            int temp = q.top();
            temp -= v[i];
            q.pop();
            q.push(temp);
        }
    }
    cout<<1;
    return 0;
}
