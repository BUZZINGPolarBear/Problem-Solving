//
//  안녕.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    long long ans = 0;
    vector<int> a, b;
    vector<pair<int, int> > v_pair, dp;
    
    cin>>n;
    for(int i=0; i<n; i++){
        int input;
        cin>>input;
        v_pair.push_back({input, 0});
    }
    for(int i=0; i<n; i++){
        int input, temp;
        cin>>input;
        temp = v_pair[i].first;
        
        v_pair[i] = {temp, input};
    }
    
    sort(v_pair.begin(), v_pair.end());
    
    dp.push_back(v_pair[0]);
    for(int i=1; i<v_pair.size(); i++){
        if(dp[i-1].first + v_pair[i].first < 100) dp.push_back({dp[i-1].first + v_pair[i].first, dp[i-1].second + v_pair[i].second});
        else{
            int j=0;
            for(j; j<i; j++){
                if(dp[i-1].first + dp[j].first>100) break;
            }
            
        }
    }
    
    
}
