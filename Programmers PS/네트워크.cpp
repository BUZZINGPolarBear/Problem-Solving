//
//  네트워크.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/08.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int> > v(n+5), visited(n+5);

    for(int i=0; i<computers.size(); i++){
        vector<int> temp_v = computers[i];
        for(int j=0; j<n; j++){
            if(temp_v[j] == 1){
                v[i+1].push_back(j+1);
                visited[i+1].push_back(0);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        queue<int> q;
        for(int j=0; j<v[i].size(); j++){
            if(visited[i][j] == 0) {
                q.push(v[i][j]);
                visited[i][j] = answer++;
            }
            
            while(!q.empty()){
                int front = q.front();
                q.pop();
                
                for(int j=0; j<v[front].size(); j++){
                    if(visited[front][j] == 0){
                        q.push(v[front][j]);
                        visited[front][j] = 1;
                    }
                }
                
            }
        }
        
        
    }
        
    
    return answer;
}

int main(){
    cout<<solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}});
//    cout<<solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
    return 0;
}
