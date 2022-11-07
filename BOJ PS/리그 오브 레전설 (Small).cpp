//
//  리그 오브 레전설 (Small).cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/05.
//

#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<long long> v(n+10);
    
    for(int i=1; i<m; i++){
        v[i] = 1;
    }
    v[m] = 2;
    
    for(int i=m+1; i<=n; i++){
        v[i] = (v[i-1]%MOD + v[i-m]%MOD)%MOD;
    }
    
    cout<<v[n]%MOD;
    
    return 0;
}
