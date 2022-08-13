//
//  k번째 수.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/12.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(auto i : commands){
        vector<int> tempV;
        for(int j=i[0]-1; j<i[1]; j++){
            tempV.push_back(array[j]);
        }
        sort(tempV.begin(), tempV.end());
        answer.push_back(tempV[i[2]-1]);
    }
    
    
    return answer;
}

int main(){
    vector<int> ans = solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
    
    for(auto i : ans){
        cout << i <<" ";
    }
}
