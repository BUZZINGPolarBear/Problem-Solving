//
//  안녕.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int dp[105][105] = {0, };
int h[105]={0, }, p[105]={0, };

int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        h[i] = temp;
    }
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        p[i] = temp;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=100; j++){
            if(j - h[i] >=0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i]] + p[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][99];
    
    return 0;
}
