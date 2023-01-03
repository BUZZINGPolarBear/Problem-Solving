//
//  트럭.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/02.
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
    int n, w, l;
    cin>>n>>w>>l;
    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    cout<<solution(w, l, v);
    
    return 0;
}
