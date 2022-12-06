//
//  할인행사.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/06.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> want_num_map;
    
    for(int i=0; i<number.size(); i++){
        want_num_map[want[i]] = number[i];
    }
        
    for(int i=0; i<=discount.size() - 10; i++){
        unordered_map<string, int> temp_map;
        for(int j=i; j<i+10; j++){
            temp_map[discount[j]] += 1;
        }
        
        if(temp_map == want_num_map) {
            cout<<i<<"\n";
            answer ++;
        }
    }
    
    return answer;
}
