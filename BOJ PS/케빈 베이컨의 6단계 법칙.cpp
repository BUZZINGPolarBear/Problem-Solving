//
//  케빈 베이컨의 6단계 법칙.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/03/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
vector<int> v[100];

void input(){
    cin>>n>>m;
    
    int left, right;
    for(int i=0; i<m; i++){
        cin>>left>>right;
        
        v[left].push_back(right);
        v[right].push_back(left);
    }
}


int solve(){
    int min_ans = 987654321;
    int idx_ans;
    
    for(int i=1; i<=n; i++){
        int local_sum=0;
        int visited[100] = {0, };
        queue<int> q;
        
        visited[i] = 1;
        for(int j=0; j<v[i].size(); j++) {
            q.push(v[i][j]);
            visited[v[i][j]] = 1;
        }
        
        while(!q.empty()){
            int front = q.front();
            
            q.pop();
            for(int j=0; j<v[front].size(); j++){
                if(visited[v[front][j]] == 0){
                    visited[v[front][j]] = visited[front] + 1;
                    q.push(v[front][j]);
                }
            }
        }
        for(int j=1; j<=n; j++){
            if(j == i) continue;
            local_sum += visited[j];
        }
//        cout<<"\n---------------------";
//        cout<<"\n"<<i<<" 번 학생의 친구 리스트 : ";
//        for(int j=1; j<=n; j++) cout<<visited[j]<<" ";
//        cout<<"\n SUM: "<< local_sum;
        
        if(local_sum < min_ans) {
            idx_ans = i;
            min_ans = local_sum;
        }
        
    }
    
    return idx_ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    input();
    
//    cout<<"\n";
    
    cout<<solve();
    
    return 0;
}
