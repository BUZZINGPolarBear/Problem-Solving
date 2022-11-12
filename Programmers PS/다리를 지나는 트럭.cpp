//
//  다리를 지나는 트럭.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int time = 0;
    
    int now_bridge_weight = 0;
    
    queue<int> q, bridge;
    
    for(auto i:truck_weights) q.push(i);
    
    while(1){
        if(q.empty()) break;
        if(bridge.empty() == 1){
            bridge.push(q.front());
            sum += q.front();
            q.pop();
            time++;
        }
        else if(bridge.size() == bridge_length){
            sum -= bridge.front();
            bridge.pop();
        }
        else{
            if(sum + q.front() <= weight){
                bridge.push(q.front());
                sum += q.front();
                time++;
                q.pop();
            }
            else{
                bridge.push(0);
                time++;
            }
        }
    }
    
    return time + bridge_length;
}

int main(){
//    cout<<solution(100, 100, {10});
    cout<<solution(2, 10, {7, 4, 5, 6});
    return 0;
}
