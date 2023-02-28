//
//  괄호의 값.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/27.
//

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(){
    string origin_input;
    int round_cnt =0, angular_cnt = 0, answer = 0;
    char current;
    cin>>origin_input;
    
    stack<char> st;
    vector<char> v;
    
    current = st.top();
    st.pop();
    
    int temp = 1;
    
    for(int i=1; i<origin_input.size(); i++){
        
        if(st.top() == ']'){
            angular_cnt++;
            st.pop();
        }
        else if(st.top() == ')'){
            round_cnt++;
            st.pop();
        }
        
        if(st.top() == '('){
            if(current == ')') temp = 2;
            
        }
        
        
    }
    
    if(!st.empty()){
        cout<<0;
        return 0;
    }
}
