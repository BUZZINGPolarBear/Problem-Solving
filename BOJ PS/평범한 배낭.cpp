//
//  평범한 배낭.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[101][100001] = {0,};

int main(){
    int n, k;
    cin>> n >>k;
    
    vector<pair<int, int> > v;
    v.push_back({0, 0});
    
    for(int i=0; i<n; i++){
        int weight, value;
        cin>>weight>>value;
        v.push_back({weight, value});
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j - v[i].first >=0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i].first] + v[i].second);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
        
    cout<<dp[n][k];
    return 0;
}
