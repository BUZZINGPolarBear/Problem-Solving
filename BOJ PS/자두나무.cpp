//
//  자두나무.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[31][3][1001];
int v[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t, w;
    cin>>t>>w;
        
    for(int i=1; i<=t; i++) cin>>v[i];
    
    for(int j = 0; j <= w; j++){
        for(int i = 1; i <= t; i++){
            if(j==0) dp[j][1][i] = dp[j][1][i-1] + (v[i]==1);
            else{
                dp[j][1][i] = max(dp[j][1][i-1] + (v[i] == 1), dp[j-1][2][i-1] + (v[i] == 1));
                dp[j][2][i] = max(dp[j][2][i-1] + (v[i] == 2), dp[j-1][1][i-1] + (v[i] == 2));
            }
            
//            cout<<"dp["<<j<<"]["<<1<<"]["<<i<<"] = "<<dp[j][1][i]<<endl;
//            cout<<"dp["<<j<<"]["<<2<<"]["<<i<<"] = "<<dp[j][2][i]<<endl;
//            cout<<"-------------------------------\n";
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= w; j++)
    {
        ans = max(ans, max(dp[j][1][t], dp[j][2][t]));
    }
    
    cout<<ans;
    return 0;
}
