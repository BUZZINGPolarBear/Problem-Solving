//
//  회사 문화 1.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/14.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    vector<pair<int, int> > v(n+1);
    
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        
        v[i].first = temp;
        v[i].second = 0;
    }
    
    for(int i=0; i<m; i++){
        int idx, w;
        cin>>idx>>w;
        
        v[idx].second += w;
    }
    
    for(int i=1; i<=n; i++){
        if(v[i].first == -1) continue;
        v[i].second += v[v[i].first].second;
    }
    for(int i=1; i<=n; i++){
        cout<<v[i].second<<" ";
    }
    return 0;
}
