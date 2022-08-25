//
//  시저 암호.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const char lower_alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char big_alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.size(); i++){
        int temp;
        if(s[i] == ' '){
            answer += " ";
            continue;
        }
        if(islower(s[i]) != 0){
            //소문자인 경우
            for(int j=0; j<26; j++){
                if(lower_alpha[j] == s[i]) {
                    temp = j;
                    break;
                }
            }
            temp = (temp + n)%26;
            
            answer += lower_alpha[temp];
        }
        else {
            //대문자인 경우
            for(int j=0; j<26; j++){
                if(big_alpha[j] == s[i]) {
                    temp = j;
                    break;
                }
            }
            temp = (temp + n)%26;
            
            answer += big_alpha[temp];
        }
    }
    return answer;
}

int main(){
    cout<<solution("z Z c", 1);
    return 0;
}
