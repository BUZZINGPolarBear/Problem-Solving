//
//  스타트링크.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/05.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;
    
    vector<int> v(f+1), visited(f+1);
    queue<int> q;
    
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        if(front + u <= f){
            if(visited[front + u] == 0){
                q.push(front + u);
                visited[front + u] = visited[front] + 1;
            }
        }
        
        if(front - d > 0){
            if(visited[front - d] == 0){
                q.push(front - d);
                visited[front - d] = visited[front] + 1;
            }
        }
    }
    
    if(visited[g] == 0) cout<<"use the stairs";
    else cout<<visited[g]-1;
    
    return 0;
}
