//
//  두큐합 같게 만들기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/01.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long answer = 0;
    long long q_size = queue1.size();
    long long sum_q1=0, sum_q2=0;
    long long target=0;
    long long q1_pointer = 0;
    long long q2_pointer = 0;
    queue<int> q1, q2;
    
    for(auto i: queue1) {
        sum_q1 += i;
        q1.push(i);
    }
    for(auto i:queue2) {
        q2.push(i);
        sum_q2 += i;
    }
    target = (sum_q1 + sum_q2)/2;
    
    while(sum_q1 != sum_q2){
        if(answer > q1.size() + q2.size() + 2) return -1;
        
        if(sum_q1<sum_q2){
            q1.push(q2.front());
            sum_q1 += q2.front();
            sum_q2 -= q2.front();
            q2.pop();
        }
        
        else{
            q2.push(q1.front());
            sum_q1 -= q1.front();
            sum_q2 += q1.front();
            q1.pop();
        }
        answer++;
    }
    return answer;
}
