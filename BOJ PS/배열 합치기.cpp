//
//  배열 합치기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/06.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    
    
    cin>>n>>m;
    vector<long long> v(n+m);
    for(int i=0; i<n+m;i++){
        cin>>v[i];
    }
    
    sort(v.begin(), v.end());
    for(auto i:v){
        cout<<i<<" ";
    }
}
