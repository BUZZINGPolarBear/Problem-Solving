//
//  극장 좌석.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[45];
long long vip[45];
void print_dp(int n){
    cout<<"\n-----------------------------\n";
    for(int i=1; i<=n; i++) cout<<dp[i]<<" ";
    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    long long ans = 1;
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        
        vip[i] = temp;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
    
    int start =0;
    for(int i=0; i<m; i++){
        int end = vip[i];
        ans *= dp[end - start - 1];
        start = end;
    }
    
    ans *= dp[n-start];
    
//    print_dp(n+1);
    
    cout<<ans;
    return 0;
}
