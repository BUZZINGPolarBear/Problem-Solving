//
//  폰켓몬.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/12.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = -100;
    unordered_set<int> set;
    for(auto i : nums) set.insert(i);
    
    int types = int(set.size());
    
    if(types <= nums.size()/2) answer = types;
    else answer = nums.size()/2;
    
    return answer;
}

int main(){
    vector<int> v = {3,3,3,2,2,2};
    cout<<solution(v);
    
    return 0;
}
