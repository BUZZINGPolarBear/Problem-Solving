//
//  전력망을 둘로 나누기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/01.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int min_differ = 100000;
    sort(wires.begin(), wires.end());
    
    for(int i=0; i<wires.size(); i++){
        int left_start = wires[i][0];
        int right_start = wires[i][1];
        
        queue<int>q1;
        int visited_q1[100] = {0, };
        int q1_size = 0, q2_size=0;
        q1.push(left_start);
        
        while(!q1.empty()){
            int now = q1.front();
            visited_q1[now] = 1;
            q1_size++;
            q1.pop();
            
            for(int i=0; i<wires.size(); i++){
                int second = 0;
                if(wires[i][0] == now) second = wires[i][1];
                else if(wires[i][1] == now) second = wires[i][0];
                else continue;
                
                if(second == right_start) continue;
                
                if(visited_q1[second] != 0) continue;
                else {
                    visited_q1[second] = 1;
                    q1.push(second);
                    q1_size++;
                }
                
                
            }
        }
        
        queue<int>q2;
        int visited_q2[100] = {0, };
        q2.push(right_start);
        
        while(!q2.empty()){
            int now = q2.front();
            visited_q2[now] = 1;
            q2_size++;
            q2.pop();
            
            for(int i=0; i<wires.size(); i++){
                int second = 0;
                if(wires[i][0] == now) second = wires[i][1];
                else if(wires[i][1] == now) second = wires[i][0];
                else continue;
                
                if(second == left_start) continue;
                
                if(visited_q2[second] != 0) continue;
                else {
                    visited_q2[second] = 1;
                    q2.push(second);
                    q2_size++;
                }
            }
        }
        
        int temp = q1_size - q2_size;
        if(temp<0) temp *= -1;
        
        temp < min_differ ? min_differ = temp : min_differ;
    }
    return min_differ/2;
}


int main(){
    cout<< solution(7, {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}});
    return 0;
}
