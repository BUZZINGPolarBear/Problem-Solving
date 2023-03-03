//
//  카드놓기 DFS풀이.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/03/01.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool visited[15] = {0, };
int n, k;
vector<string> inputV, tempV;
set<string> ansSet;



void input(){
    cin>>n>>k;
    string temp;
    
    for(int i=0; i<n; i++){
        cin>>temp;
        inputV.push_back(temp);
    }
}

void solve(int cnt){
    if(cnt == k){
        string local_str = "";
        for(int i=0; i<k; i++) local_str += tempV[i];
        
        ansSet.insert(local_str);
    }
    
    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            tempV.push_back(inputV[i]);
            
            solve(cnt+1);
            tempV.pop_back();
            visited[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    input();
    solve(0);
    
    cout<<ansSet.size();
    return 0;
}
