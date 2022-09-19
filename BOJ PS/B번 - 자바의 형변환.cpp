//
//  B번 - 자바의 형변환.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/17.
//

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> v[100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    int temp_n = 0;
    map<string, int> map;
    
    cin>>n;
    
    
    for(int i=0; i<n-1; i++){
        string a, b;
        
        cin>>a>>b;
        
        if(map.find(a) == map.end())map.insert({a,temp_n++});
        if(map.find(b) == map.end())map.insert({b,temp_n++});
        
        
        v[map.find(a)->second].push_back(map.find(b) -> second);
    }
    
    string son, parent;
    cin>> son >> parent;
    
    queue<int> q, qq;
    
    q.push(map.find(son)->second);
    
    while(!q.empty()){
        int front = q.front();
        if(front == map.find(parent) -> second){
            cout<< 1;
            return 0;
        }
        q.pop();
        
        for(int i=0; i<v[front].size(); i++){
            q.push(v[front][i]);
        }
    }
    
    qq.push(map.find(parent)->second);
    
    while(!qq.empty()){
        int front = qq.front();
        if(front == map.find(son) -> second){
            cout<< 1;
            return 0;
        }
        qq.pop();
        
        for(int i=0; i<v[front].size(); i++){
            qq.push(v[front][i]);
        }
    }
    
    cout<<0;
    return 0;
}
