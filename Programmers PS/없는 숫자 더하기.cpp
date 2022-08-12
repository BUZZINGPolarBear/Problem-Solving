//
//  없는 숫자 더하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(auto i:numbers){
        answer -= i;
    }
    return answer;
}

int main(){
    vector<int> numbers ={1,2,3,4,6,7,8,0};
    cout<<solution(numbers);
    
    return 0;
}
