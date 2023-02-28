//
//  거짓말.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int parent[55] ={0, };

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a<b) parent[b] = a;
    else parent[a] = b;
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) parent[i] = i;
    
    vector<int> true_man;
    int true_man_cnt;
    
    cin>>true_man_cnt;
    for(int i=0; i<true_man_cnt; i++){
        int temp;
        cin>>temp;
        true_man.push_back(temp);
    }
    
    for(int i=0; i<m; i++){
        int man_cnt;
        vector<int> party_man;
        cin>>man_cnt;
        int is_trueman_find = -10;
        
        for(int j=0; j<man_cnt; j++){
            int temp;
            cin>>temp;
            
            party_man.push_back(temp);
            
            for(auto k : true_man){
                if(temp == k) is_trueman_find = k;
            }
        }
        
        if(is_trueman_find != -10){
            for(int k=0; k<party_man.size(); k++){
                unionParent(party_man[k], is_trueman_find);
            }
        }
    }
    map <int, int> map;
    int ans = 1;
    for(int i=1; i<=n; i++) {
        
        bool is_trueman_find = 0;
        
        for(auto j:true_man){
            if(parent[i] == j) is_trueman_find = 1;
        }
        if(is_trueman_find) map.insert({parent[i], ans++});
    }
    cout<<ans-1;
    return 0;
}
