//
//  올바른 괄호.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <stack>
#include<string>

using namespace std;

bool solution(string s)
{
    if(s[0]==')'){
        return 0;
    }
    
    bool answer = true;

    int temp = 0;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') temp++;
        else {
            temp--;
            if(temp < 0) return false;
        }
    }
    
    if(temp == 0) answer = true;
    else answer = false;
    
    return answer;
}
