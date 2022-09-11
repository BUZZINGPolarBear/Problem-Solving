//
//  괄호 회전하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/10.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int checker(string s){
    stack<char> st;
    
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else{
            if(st.empty()) return 0;
            if(s[i]==')' && st.top()=='(') st.pop();
            if(s[i]==']' && st.top()=='[') st.pop();
            if(s[i]=='}' && st.top()=='{') st.pop();
        }
    }
    
    if(st.size() == 0)return 1;
    else return 0;
}

int solution(string s) {
    int answer = 0;
    string original = s;
    queue<int> q;
    
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<i; j++){
            s += s[0];
            s = s.substr(1);
        }
        
        answer += checker(s);
        s = original;
    }
    
    return answer;
}

int main(){
    cout<<solution("}]()[{");
    
    return 0;
}
