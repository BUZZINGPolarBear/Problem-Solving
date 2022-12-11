//
//  폴짝폴짝.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/07.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, a, b;
    int jmp_cnt = 1;
    queue<int> q;
    cin>>n;
    vector<int> field(n+1), visited(n+1);
    
    for(int i=1; i<=n; i++){
        cin>>field[i];
    }
    
    cin>>a>>b;
    
    q.push(a);
    visited[a] = jmp_cnt;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(int i=1; front + i*field[front] <= n; i++){
            if(visited[front + i*field[front]] != 0) continue;
            
            visited[front + i*field[front]] = visited[front];
            q.push(front + i*field[front]);
        }
        
        jmp_cnt++;
    }
    
    if(visited[b] != 0) cout<<visited[b];
    else cout<<-1;
    
    return 0;
}
