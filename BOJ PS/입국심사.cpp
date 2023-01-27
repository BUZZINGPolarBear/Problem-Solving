//
//  입국심사.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<unsigned long long> v;


void input(){
    cin>>n>>m;
    v.resize(n);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    
    sort(v.begin(), v.end());
}

void find_ans(){
    unsigned long long start = 0;
    unsigned long long end = v.back()*m;
    unsigned long long ans= 1000000000000000001;
    
    while(start <= end){
        unsigned long long mid = (start+end)/2;
        
        unsigned long long cnt = 0;
        for(int i=0; i<n; i++){
            cnt += mid/v[i];
        }
        
        if(cnt < m) start = mid + 1;
        else {
            ans = min(ans, mid);
            end = mid - 1;
        }
    }
    
    cout<<ans;
    return;
}

void solve(){
    input();
    find_ans();
    
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    
    return 0;
}
