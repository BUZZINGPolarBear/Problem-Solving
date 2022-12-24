//
//  구간 합 구하기 4.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/24.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    
    vector<int> sum(n+1);
    sum.push_back(0);
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        
        sum[i] = sum[i-1] + temp;
    }
    
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<"\n";
    }
    return 0;
}
