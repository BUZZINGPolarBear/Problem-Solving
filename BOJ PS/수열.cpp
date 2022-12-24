//
//  수열.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/24.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k;
    long long ans = -10000000000;
    cin>>n>>k;
    vector<long long>sum(n+1);
    
    sum[0] = 0;
    cin>>sum[1];
    for(int i=2; i<=n; i++){
        int temp;
        cin>>temp;
        
        sum[i] = sum[i-1]+temp;
    }
    
    for(int i=k; i<=n; i++){
        long long temp = sum[i] - sum[i-k];
        if(ans < temp) ans = temp;
    }
    cout<<ans;
    return 0;
}
