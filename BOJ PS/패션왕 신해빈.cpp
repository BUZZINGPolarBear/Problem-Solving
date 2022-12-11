//
//  패션왕 신해빈.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/11.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        int n, ans = 1;
        map<string, int> clothes;
        vector<int> v, mask_v;
        cin>>n;
        
        if(n==0){
            cout<<0<<"\n";
            continue;
        }
        for(int i=0; i<n; i++){
            string first, second;
            cin>>first>>second;
            
            if(clothes.find(second) == clothes.end()){
                //not found
                clothes.insert({second, 1});
            }else clothes[second] += 1;
        }
        
        for(auto i=clothes.begin(); i != clothes.end(); i++) v.push_back(i->second);
        
        for(int i=0; i<v.size(); i++){
            ans *= v[i]+1;
        }
        
        cout<<ans-1<<"\n";
    }
}
