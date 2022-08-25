//
//  이상한 문자 만들기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> v;
    
    s += ' ';
    while(s.size()){
        v.push_back(s.substr(0, s.find(' ')));
        s = s.substr(s.find(' ')+1, s.size());
    }
    
    for(auto i : v){
        for(int j=0; j<i.size(); j++){
            if(j%2 == 0){
                answer += toupper(i[j]);
            }
            else{
                answer += tolower(i[j]);
            }
        }
        answer += ' ';
    }
    return answer.substr(0, answer.size()-1);
}

int main(){
    cout<<solution("try hello world");
    return 0;
}
