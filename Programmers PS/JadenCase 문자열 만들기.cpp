//
//  JadenCase 문자열 만들기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/10.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    s = ' '+s;
    for(int i=0; i<=s.size(); i++){
        if(s[i-1] == ' '){
            int temp = s[i] - 'a';
            
            if('a'<s[i] && s[i]<'z'){
                answer += 'A' + temp;
            }
            else answer+=s[i];
            cout<<answer<<endl;
        }
        else answer += s[i];
    }
    
    return answer.substr(1);
}

int main(){
    cout<<solution("3people unFollowed me");
    
    return 0;
}
