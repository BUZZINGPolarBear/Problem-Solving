//
//  체육복.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/13.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]==reserve[j]){
                answer ++;
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if((lost[i]-1 == reserve[j] || lost[i]+1 == reserve[j])){
                answer++;
                reserve[j] = -1;
                break;
            }
        }
    }
    
    return answer;
}

int main()
{
    cout << solution(5, vector<int> {2,4}, vector<int> {1,3,5});
    return 0;
}
