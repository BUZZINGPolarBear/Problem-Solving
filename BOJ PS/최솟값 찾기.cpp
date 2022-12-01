//
//  최솟값 찾기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/30.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    deque<pair<long long, long long> > dq;
    int n, l;
    cin>>n>>l;
    
    for(int i=0; i<n; i++){
        long long x;
        cin >> x;
        
        while(!dq.empty() && dq.back().first >= x){
            dq.pop_back();
        }
        
        dq.push_back({x, i});
        
        if(dq.front().second <= i - l) dq.pop_front();
        
        cout<<dq.front().first<<" ";
    }
    
    return 0;
}
