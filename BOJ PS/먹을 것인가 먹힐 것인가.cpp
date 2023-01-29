//
//  먹을 것인가 먹힐 것인가.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/29.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(){
    int t;
    
    cin>>t;
    while(t--){
        int n, m;
        
        cin>>n>>m;
        vector<int> a(n), b(m);
        
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<m; i++) cin>>b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int cnt =0;
        
        for(int i=0; i<a.size(); i++){
            int a_num = a[i];
            int left = 0;
            int right = m;
            
            while(left+1 < right){
                int mid = (left+right)/2;
                
                if(b[mid] < a_num){
//                    cout<<"\n--------------\n"<<a_num<<" - "<<b[mid]<<"\n";
                    left = mid;
                }
                else right = mid;
            }
            
            cnt += left;
            if(a_num > b[left]) cnt++;
        }
        
        cout<<cnt<<"\n";
        
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
}
