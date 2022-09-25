//
//  집합의 표현.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[1000001] = {0, };

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a<b) parent[b] = a;
    else parent[a]  = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    for(int i=0; i<m; i++){
        int type, a, b;
        
        cin>>type>>a>>b;
        
        if(type == 0){
            unionParent(a, b);
        }
        else if(type == 1){
            bool result = findParent(a, b);
            if(result == true) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    
    
}
