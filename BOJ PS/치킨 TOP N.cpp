//
//  치킨 TOP N.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> v;

void input(){
    cin>>n;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    cin>>k;
}

void solve(){
    input();
    
    int idx = 0;
    while(idx < n){
        sort(v.begin()+idx, v.begin()+idx+(n/k));
        idx += (n/k);
    }
    
    for(auto i: v){
        cout<<i<<" ";
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
