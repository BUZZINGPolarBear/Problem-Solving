//
//  제일 작은 수 제거하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 1000000;
    if(arr.size()==1) return {-1};
    
    for(auto i : arr){
        if(i < min) min = i;
    }
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i] != min) answer.push_back(arr[i]);
    }
    return answer;
}
