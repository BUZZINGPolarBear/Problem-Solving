//
//  눈 치우기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/13.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, ans=0;
    queue<int> q;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    sort(v.rbegin(), v.rend());
    
    while (v[0] != 0) {
        if(v.size() >= 2){
            for(int i=0; i<2; i++){
                v[i] -= 1;
            }
            ans++;
        }
        else{
                v[0] -= 1;
                ans++;
        }
        sort(v.rbegin(), v.rend());
    }
    
    if(ans >1440) cout<<-1;
    else cout<<ans;
    return 0;    
}
