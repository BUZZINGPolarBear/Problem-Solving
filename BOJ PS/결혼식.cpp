//
//  결혼식.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/26.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int visited[505] = {0, };
int field[505][505] = {0, };

void show_tree(int n){
    cout<<"=========현재 트리 상태============\n";
    for(int i=0; i<n; i++){
        cout<<visited[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    int n, m;
    queue<int> q;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        
        field[a][b] = 1;
        field[b][a] = 1;
        if(a==1){
            q.push(b);
            visited[b] = 1;
            ans++;
        }
    }
//    show_tree(n);
    visited[1] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int i=1; i<=n; i++){
            if(field[now][i] == 1 && visited[i] == 0){
                visited[i] = visited[now]+1;
                q.push({i});
                
                if(visited[i] == 2) ans++;
            }
        }
//        show_tree(n);
    }
    
    cout<<ans;
    return 0;
}
