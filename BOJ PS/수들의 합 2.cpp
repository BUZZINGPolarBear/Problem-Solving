//
//  수들의 합 2.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;

void input(){
    cin>>n>>m;
    int temp;
    
    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
    }
}

void solve(){
    input();
    
    int left = 0;
    int right = 0;
    int ans = 0;
    int sum = v[0];
    
    while(right < n){
        if(sum == m) ans++;
        
        if(left==right){
            right += 1;
            sum += v[right];
        }
        else if(sum >= m){
            sum -= v[left];
            left += 1;
        }
        else if(sum < m){
            right += 1;
            sum += v[right];
        }
        
    }
    
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
