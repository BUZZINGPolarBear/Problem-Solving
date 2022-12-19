//
//  선긋기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    int x, y;
    vector<pair<int, int> > v;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>x>>y;
        v.push_back({x, y});
    }
    
    sort(v.begin(), v.end());
    
    int start = v[0].first, end = v[0].second, ans=0;
    for(int i=0; i<n; i++){
        if(end < v[i].first){
            //새 선분
            ans += end - start;
            start = v[i].first;
        }
        if(end < v[i].second){
            //선분 확장
            end = v[i].second;
        }
    }
    
    ans += end-start;
    
    cout<<ans;
    return 0;
}
