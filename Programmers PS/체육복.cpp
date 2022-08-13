//
//  체육복.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/13.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v;
    v.push_back(0);
    for(int i=1; i<=n; i++) v.push_back(1);
    for(int i=0; i<reserve.size(); i++) v[reserve[i]]+=1;
    
    v.push_back(0);
    for(int i=0; i<lost.size(); i++){
        if(v[lost[i]]>1) v[lost[i]] -= 1;
        else if(v[lost[i]]<=1){
            if(v[lost[i]-1] <= v[lost[i]+1]){
                v[lost[i]-1] -= 1;
                v[lost[i]] += 1;
            }
            else {
                v[lost[i]-1] += 1;
                v[lost[i]] += 1;
            }
        }
    }
    
    
    for(int i = 1; i<=n; i++ ){
        if(v[i]>=1) answer++;
    }
    
    return answer;
}

int main()
{
    cout << solution(5, vector<int> {2,4}, vector<int> {1,3,5});
    return 0;
}
