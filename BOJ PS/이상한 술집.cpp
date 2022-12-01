//
//  이상한 술집.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n, long long k, vector<long long> v);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    long long n, k;
    cin >>n >> k;
    vector<long long> v(n);
    
    for(long long i=0; i<n; i++) cin>>v[i];
    
    cout<<solution(n, k, v);
    return 0;
}

long long solution(long long n, long long k, vector<long long> v){
    sort(v.begin(), v.end());
    long long right = v[n-1]+1, left=1, ans=0;
    long long mid = 0;
    
    while(left<right){
        mid = (left + right) / 2;
        
        long long temp_man = 0;
        for(long long i=0; i<n; i++){
            temp_man += v[i] / mid;
        }
        
        if(temp_man >= k){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid;
        }
        
    }

    
    return left-1;
}
