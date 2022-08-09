//
//  로또의 최고순위와 최저순위.cpp
//  BOJ PS
//
//  Created by joonhwi on 2022/08/09.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    sort(lottos.rbegin(), lottos.rend());
    sort(win_nums.rbegin(), win_nums.rend());
    vector<int> answer;
    
    int max_same=0, zero_cnt=0;
    
    for(int i=0; i<lottos.size(); i++)
    {
        if(lottos[i]==0) {
            zero_cnt++;
            continue;
        }
        for(int j=0; j<win_nums.size(); j++)
        {
            if(lottos[i]==win_nums[j]) max_same ++;
        }
        
    }
    
    cout<<"max_same: "<<max_same<<endl;
    cout<<"zero_cnt: "<<zero_cnt<<endl;

    if(max_same==0 && zero_cnt==0)
    {
        answer.push_back(6);
    }
    else{
        answer.push_back(7-(max_same+zero_cnt));
    }
    
    if(max_same == 0)
    {
        answer.push_back(6);
    }
    else answer.push_back(7-max_same);
    
    
    
    return answer;
}

int main()
{
    
    vector<int> lottos = {1, 2, 3, 4, 5, 6};
    vector<int> win_nums = {7, 8, 9, 45, 10, 35};
    
    vector<int> ans = solution(lottos, win_nums);
    
    cout<<ans[0]<<" "<<ans[1];
    
    return 0;
}
