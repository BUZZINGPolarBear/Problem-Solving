//
//  소가 길을 건너간 이유 5.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/28.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, b;
vector<int> v;

void input(){
    cin>>n>>k>>b;
    int temp;
    
    for(int i=1; i<=n; i++) v.push_back(0);
    
    for(int i=0; i<b; i++){
        cin>>temp;
        v[temp] = 1;
    }
}

void solve(){
    int left = 1;
    int right = 1;
    int have_to_fix = v[1];
    int ans = 987654321;
    
    while(right <= n){
        int between = right - left + 1;
        if(between == k){
            ans = min(have_to_fix, ans);
            
            have_to_fix -= v[left];
            left += 1;
        }
        
        else if(between < k){
            right++;
            
            have_to_fix+=v[right];
        }
        else if(between > k){
            have_to_fix -= v[left++];
        }
        
    }
    
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    input();
    solve();
}
