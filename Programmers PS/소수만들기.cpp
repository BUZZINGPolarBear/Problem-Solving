//
//  소수만들기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/12.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());
    
    vector<int> temp;
    for(int i=0; i<nums.size(); i++)
    {
        if(i<3) temp.push_back(1);
        else temp.push_back(0);
    }
    
    do{
        int plus_temp = 0;
        for(int i=0; i<nums.size(); i++){
            if(temp[i]==1){
                plus_temp += nums[i];
            }
        }
        bool flag = true;
        for(int i=2; i<plus_temp; i++){
            if(plus_temp % i == 0) flag = false;
        }
        if(flag) answer++;
    }while(prev_permutation(temp.begin(), temp.end()));
        
    return answer;
}

int main()
{
    vector<int> nums = {1,2,7,6,4};
    cout << solution(nums);
    
    return 0;
}
