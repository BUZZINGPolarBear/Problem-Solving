//
//  문자열 다루기 기본.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() != 4 && s.size() != 6) return 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]<'0' || s[i]>'9') return 0;
    }
    return answer;
}

int main(){
    cout<<solution("9999");
    return 0;
}
