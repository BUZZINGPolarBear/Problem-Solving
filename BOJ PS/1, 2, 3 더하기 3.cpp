//
//  1, 2, 3 더하기 3.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000009
using namespace std;

long long ans;
vector<long long> v;

void solve(){
    int t;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    v.push_back(13);
    
    cin>>t;
    
    while(t--){
        ans = 0;
        int temp;
        cin>>temp;
        
        if(temp <= v.size()){
            cout<<v[temp] % MOD<<"\n";
        }
        else{
            for(int i=v.size(); i<=temp; i++){
                v.push_back(((v[i-1]%MOD) + (v[i-2]%MOD) + (v[i-3]%MOD))%MOD);
            }
            cout<<v[temp]<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
