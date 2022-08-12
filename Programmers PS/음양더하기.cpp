//
//  음양더하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/12.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i=0; i<absolutes.size(); i++){
        if(signs[i]==false) answer -= absolutes[i];
        else answer += absolutes[i];
    }
    return answer;
}

int main(){
    vector<int> v = {4,7,12};
    vector<bool> vs = {false,false,true};
    
    cout<< solution(v, vs);
    return 0;
}

