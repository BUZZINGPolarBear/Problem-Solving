//
//  순서쌍의 곱의 합.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/19.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, ans =0;
    cin>>n;
    vector<long long> v, particial_sum_v;
    
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        if(i==0) particial_sum_v.push_back(temp);
        else particial_sum_v.push_back(temp + particial_sum_v[i-1]);
    }
    
    for(int i=0; i<n-1; i++){
        ans += (particial_sum_v[n-1] - particial_sum_v[i]) * v[i];
    }
 
    
    cout<<ans;
    return 0;
}
