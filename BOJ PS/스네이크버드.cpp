//
//  스네이크버드.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, l;
    
    cin>>n>>l;
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(auto idx:v){
        if(idx <= l) l++;
    }
    
    cout<<l;
    return 0;
}
