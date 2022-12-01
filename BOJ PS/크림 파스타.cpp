//
//  크림 파스타.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long, long> > v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin>>n;
    
    int temp =0;
    cin>>temp;
    long long min = temp;
    v.push_back({temp, 0});
    cout<<"0 ";
    
    for(int i=1; i<n; i++){
        int temp;
        cin >>temp;
        
        temp < min ? min=temp: temp;
        
        if(temp - min > v[i-1].second){
            v.push_back({temp, temp - min});
        }
        else{
            v.push_back({temp, v[i-1].second});
        }
        
        cout<<v[i].second<<" ";
    }
    
    return 0;
}
