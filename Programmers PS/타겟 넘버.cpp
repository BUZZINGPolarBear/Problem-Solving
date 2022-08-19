//
//  타겟 넘버.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/18.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

long long visited[1048580];
int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q;
    
    q.push(numbers[0]);
    q.push(-1*numbers[0]);
    
    for(int i=1; i<numbers.size(); i++){
        int len = q.size();
        for(int j=0; j<len; j++){
            int front = q.front();
            q.pop();
            q.push(front + numbers[i]);
            q.push(front - numbers[i]);
        }
    }
    
    while(!q.empty()){
        if(q.front() == target) answer++;
        q.pop();
    }
    
    return answer;
}

int main(){
    cout<<solution({4, 1, 2, 1}, 4);
    
    return 0;
}
