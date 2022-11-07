//
//  이건 꼭 풀어야해.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/05.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long sum = 0;
    int n, q;
    cin>>n>>q;
    
    vector<long long> v(n+1);
    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        sum += v[i];
        v[i] = sum;
    }
    
    for(int i=0; i<q; i++){
        int l, r;
        
        cin>>l>>r;
        
        cout<<v[r]-v[l-1]<<"\n";
    }
    
    return 0;
}
