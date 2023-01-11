//
//  퇴사 2.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/11.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[1500005];

void print_dp(int n){
    cout<<"\n--------------------\n";
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    long long local_max = -1000;
    long long ans = 0;
    
    for(int i=1; i<=n; i++){
        long long t, p;
        cin>>t>>p;
        local_max = max(local_max, dp[i]);
//        dp[i] = local_max;
        
        if(i+t <= n+1){
            dp[i+t] = max(local_max+p, dp[i+t]);
        }
//        print_dp(n+1);
    }
    
    
    cout<<max(local_max, dp[n+1]);
    return 0;
}




