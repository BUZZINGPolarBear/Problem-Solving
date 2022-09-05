//
//  기능개발.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/06.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> progress_q, speed_q;
    
    for(int i=0; i<progresses.size(); i++){
        progress_q.push(progresses[i]);
        speed_q.push(speeds[i]);
    }
    
    while(!progress_q.empty()){
        for(int i=0; i<progress_q.size(); i++){
            int temp = progress_q.front();
            temp += speed_q.front();
            
            progress_q.push(temp);
            progress_q.pop();
            
            speed_q.push(speed_q.front());
            speed_q.pop();
        }
        
        int ans_temp = 0;
        while(!progress_q.empty()){
            if(progress_q.front()>=100){
                ans_temp ++;
                
                progress_q.pop();
                speed_q.pop();
            }
            else break;
        }
        if(ans_temp>0) answer.push_back(ans_temp);
    }
    
    return answer;
}

int main(){
    
    vector<int> ans_temp = solution({93, 30, 55}, {1, 30, 5});
    
    for(auto i : ans_temp){
        cout<<i<<" ";
    }
}
