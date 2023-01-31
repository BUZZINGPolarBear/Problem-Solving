//
//  나무 자르기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long n, m;
vector<long long> v;


void input(){
    cin>>n>>m;
    v.resize(n);
    for(int i=0; i < n; i++) cin>>v[i];
    
    sort(v.begin(), v.end());
}

void find_ans(){
    long long left = 0;
    long long right = 1e9;
    
    while(left+1 < right){
        long long mid = (left+right)/2;
        
        long long cnt = 0;
        for(int i=0; i<n; i++){
            if(v[i] > mid) cnt += v[i]-mid;
        }
        
        if(cnt >= m) left = mid;
        else right = mid;
        
    }
    
    cout<<left;
    
}

void solve(){
    input();
    find_ans();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
