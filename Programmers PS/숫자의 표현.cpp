//
//  숫자의 표현.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/22.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp;
    
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);
    dp.push_back(2);
    
    for(int i=4; i<n; i++){
        dp[i] = dp[i-3] + dp[i-2];
        cout<<dp[i]<<endl;
    }
    
    return 1;
}

int main(){
    cout<<solution(15);
}
