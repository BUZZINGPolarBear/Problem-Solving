//
//  집합의 표현 다시 풀기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/03/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int field[1001000] = {0, };

int find_parants(int x){
    if(x == field[x]) return field[x];
    
    return field[x] = find_parants(field[x]);
}

void union_parants(int a, int b){
    a = find_parants(a);
    b = find_parants(b);
    
    if(a < b) field[b] = a;
    else field[a] = b;
}

bool check_parent(int a, int b){
    int a_parent = find_parants(a);
    int b_parent = find_parants(b);
    
    if(a_parent == b_parent) return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    
    for(int i=1; i<=n; i++) field[i] = i;
    while(m--){
        int command, a, b;
        
        cin>>command>>a>>b;
        
        if(command == 0){
            union_parants(a, b);
        }
        else{
            if(check_parent(a, b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
