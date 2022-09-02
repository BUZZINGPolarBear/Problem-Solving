//
//  예산.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/02.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end());
    
    for(int i=0; i<d.size(); i++){
        budget -= d[i];
        
        if(budget < 0) break;
        else answer ++;
    }
    
    return answer;
}

int main(){
    cout<<solution({1,3,2,5,4}, 9);
    
    return 0;
}
