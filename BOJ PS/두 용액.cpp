//
//  두 용액.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/08.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    vector<long> v(n);
    pair<long, long> ans;
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    
    sort(v.begin(), v.end());
    int start = 0;
    int end = n-1;
    long sum = 2000000000;
    while(start < end){
        long local_sum = v[start] + v[end];
        
        if(abs(local_sum) < sum){
            sum = abs(local_sum);
            ans.first = start;
            ans.second = end;
            if(local_sum==0){
                break;
            }
        }
        
        if(local_sum <  0){
            start++;
        }
        
        else{
            end--;
        }
        
        
    }
   
    
    cout<<v[ans.first]<<" "<<v[ans.second];
    return 0;
}
