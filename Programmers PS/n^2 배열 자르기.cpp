//
//  n^2 배열 자르기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/10.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int first = 1;
    long long idx = 0;
    for(int i=0; i<n; i++){
        int colCnt = 0;
        while(1){
            answer.push_back(first);
            colCnt++;
    
            if(colCnt > i) break;
        }
        int temp=first+1;
        while(1){
            answer.push_back(temp++);
            colCnt++;
            
            if(colCnt > n-1) break;
        }
        first ++;
    }
    
    vector<int> solution;
    
    for(long long i=left; i<right+1; i++){
        solution.push_back(answer[i]);
    }
    
    return solution;
}
int main(){
    vector<int> v = solution(3, 2, 5);
    for(auto i: v){
        cout<< i<<" ";
    }
    
    return 0;
}
