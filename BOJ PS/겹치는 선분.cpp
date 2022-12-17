//
//  겹치는 선분.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/17.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    vector<pair<int, int> > v;
    
    cin>>n;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    
    int ans = 1;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(v[0].second);
    
    for(int i=1; i<n; i++){
        int start_point = v[i].first;
        int end_point = v[i].second;
        
        while(pq.size() && pq.top() <= start_point) pq.pop();
        pq.push(end_point);
        ans < pq.size() ? ans = pq.size() : ans;
    }
    cout<<ans;
    return 0;
}
