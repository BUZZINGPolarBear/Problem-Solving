//
//  피보나치.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/18.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    
    for(int i=2; i<20000; i++){
        int temp = v[i-1] + v[i-2];
        if(temp > 1000000000) break;
        v.push_back(temp);
    }
    
    for(int i=0; i<n; i++){
        vector<int> ans;
        int objective;
        cin >> objective;
        
        while(objective){
            for(int j = v.size(); j>=0; j--){
                if(objective - v[j] >= 0){
                    objective -= v[j];
                    ans.push_back(v[j]);
                }
            }
        }
        
        for(int j=ans.size()-2; j>0; j--){
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
}
