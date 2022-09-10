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

vector<int> arrSubstring(vector<int> v, long long left, long long right){
    vector<int> solution;
    
    
    for(int i=left; i<right+left+1; i++){
        solution.push_back(v[i]);
    }
    
    return solution;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long first = left/n  + 1;
    long long origin_gap = right - left;
    right += n;
    
    for(long long i=left; i<right;){
        for(long long j=0; j<first; j++) {
            answer.push_back(first);
            if(answer.size() > right - left) return arrSubstring(answer, left%n%n, origin_gap);
        }
        long long temp = first;
        for(long long j=first; j<n; j++){
            answer.push_back(++temp);
            if(answer.size() > right - left) return arrSubstring(answer, left%n%n, origin_gap);
        }
        first++;
    }
    
    return answer;
}


int main(){
    vector<int> v = solution(4, 7, 14);
    for(auto i: v){
        cout<< i<<" ";
    }
    
    return 0;
}
