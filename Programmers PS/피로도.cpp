//
//  피로도.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/26.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -100;
    vector<int> v(dungeons.size());
    sort(dungeons.begin(), dungeons.end());
    
    do{
        int temp = 0;
        int temp_k = k;
        for(int i=0; i<dungeons.size(); i++){
            if(temp_k < dungeons[i][0]) break;
            temp_k -= dungeons[i][1];
            temp++;
        }
        answer < temp ? answer = temp:answer;
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}

int main(){
    cout<<solution(80, {{80,20},{50,40},{30,10}});
    
    return 0;
}
