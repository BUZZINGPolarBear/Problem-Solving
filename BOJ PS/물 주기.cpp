//
//  물 주기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/26.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k, a, b;
    int ans = 0;
    cin>>n>>k>>a>>b;
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++) v.push_back({k, i});
    
    while(1){
        long long min = 987654321;
        int min_idx = -100;
        for(int i=0; i<v.size(); i++){
            if(v[i].first < min){
                if(v[i].first == 0){
                    cout<<ans;
                    return 0;
                }
                min=v[i].first;
                min_idx=v[i].second;
            }
            --v[i].first;
        }
        
        for(int i=0; i<a; i++){
            if(min_idx + i >= v.size()) continue;
            v[min_idx + i].first += b;
        }
        ans++;
    }
    return  0;
}
