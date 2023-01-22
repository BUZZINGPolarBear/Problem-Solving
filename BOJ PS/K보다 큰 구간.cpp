//
//  K보다 큰 구간.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;
int n, k;
int ans=0;

void input(){
    cin>>n;
    
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cin>>k;
}

void find_ans(){
    
    int left = 0;
    int right = 0;
    long long sum = 0;
    
    while(1){
        if(right == n){
            if( sum > k){
                ans++;
                sum -= v[left];
                left++;
                
            }
            else break;
            continue;
        }
        
        if(sum <= k){
            sum += v[right];
            right++;
        }
        else{
            ans += n-right+1;
            sum -= v[left];
            left++;
        }
    }
    
    cout<<ans;
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
