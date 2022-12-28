//
//  A.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<long long> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        
        while(1){
            sort(v.rbegin(), v.rend());
            bool one_flag = 1;
            for(int i=1; i<v.size(); i++){
                if(v[i]!=1) {
                    one_flag = 0;
                    break;
                }
            }
            v[0] = v[0]*v[1];
            v[1] = 1;
            if(one_flag == 1){
                cout<<(v[0] + v.size() - 1)*2022<<"\n";
                break;
            }
        }
    }
}
