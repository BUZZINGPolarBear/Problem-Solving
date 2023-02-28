//
//  실패율.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/17.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    sort(stages.begin(), stages.end());
    
    vector<int> answer;
    vector<pair<float, int> > fail_cnt;
    long long player_cnt = stages.size();
    
    for(int i=0; i<=N+1; i++){
        fail_cnt.push_back({0, i});
    }
    
    for(int i=0; i<stages.size(); i++){
        fail_cnt[stages[i]].first += 1;
    }
    
    for(int i=1; i<=stages.size(); i++){
        long long temp = player_cnt;
        player_cnt -= fail_cnt[i].first;
        
        if(temp <= 0) fail_cnt[i].first = 1;
        else fail_cnt[i].first = 1-(fail_cnt[i].first/temp);
    }
    
    sort(fail_cnt.begin(), fail_cnt.end());
    
    for(int i=0; i<fail_cnt.size(); i++){
        if(fail_cnt[i].second == 0 || fail_cnt[i].second == N+1) continue;
        
        answer.push_back(fail_cnt[i].second);
    }
    return answer;
}

int main()
{
    vector<int> answer = solution(3, {1, 1, 1});
    
    for (auto i : answer){
        cout << i <<" ";
    }
    return 0;
}
