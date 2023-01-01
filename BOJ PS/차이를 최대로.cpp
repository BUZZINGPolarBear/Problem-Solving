//
//  차이를 최대로.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    int ans = -987654321;
    cin>>n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end());
    
    do{
        int temp=0;
        for(int i=1; i<n; i++){
            temp += abs(v[i-1] - v[i]);
        }
        
        ans < temp ? ans = temp : ans;
    }while(next_permutation(v.begin(), v.end()));
    
    cout<<ans;
    return 0;
}
