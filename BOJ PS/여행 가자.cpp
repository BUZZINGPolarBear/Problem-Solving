//
//  여행 가자.cpp
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
int field[3000] = {0, };

int find_parent(int x){
    if(field[x] == x) return field[x];
    
    return field[x] = find_parent(field[x]);
}

void union_pair(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if(a < b) field[b] = a;
    else field[a] = b;
}

bool find_pair(int a, int b){
    int parent_a = find_parent(a);
    int parent_b = find_parent(b);
    
    if(parent_a == parent_b) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++) field[i] = i;
    
    int input_temp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>input_temp;
            
            if(input_temp){
                union_pair(i, j);
            }
        }
    }
    
    int trav_idx;
    vector<int> trav_v;
    for(int i=0; i<m; i++){
        cin>>trav_idx;
        
        trav_v.push_back(trav_idx);
    }
    
    int temp = field[trav_v[0]];
    for(int i=1; i<trav_v.size(); i++){
        if(temp != field[trav_v[i]]) {
            cout<<"NO";
            return 0;
        }
    }
    
    cout<<"YES";
    return 0;
}
