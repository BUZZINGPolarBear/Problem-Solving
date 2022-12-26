//
//  태상이의 훈련소 생활.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/26.
//

#include <iostream>
using namespace std;
long long original_sum[100005], jogyo_sum[100005] ;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    int inpt_temp;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++) cin>>original_sum[i];
    
    for(int i=0; i<m; i++){
        int a, b, k;
        cin>>a>>b>>k;
        
        jogyo_sum[a] += k;
        jogyo_sum[b+1] -= k;
    }
    
    for(int i=1; i<=n; i++){
        jogyo_sum[i] += jogyo_sum[i-1];
    }
    
    for(int i=1; i<=n; i++) {
        original_sum[i] += jogyo_sum[i];
        cout<<original_sum[i]<<" ";
    }
    return 0;
}
