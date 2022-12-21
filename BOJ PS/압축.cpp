//
//  압축.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/21.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    int left_cnt=0;
    stack<int> st;
    string input;
    cin>>input;
    
    for(int i=0; i<input.size(); i++){
        if(input[i] != ')'){
            string temp = "";
            temp = input[i];
            if(0 <= input[i]-'0' && input[i]-'0' <= 9 && input[i+1] == '(') st.push(stoi(temp));
            else if(input[i] == '(') st.push(-100);
            else st.push(1);
        }
        else if(input[i] == ')'){
            int local_ans = 0;
            while(st.top() != -100){
                local_ans += st.top();
                st.pop();
            }
            st.pop();
            local_ans *= st.top();
            st.pop();
            st.push(local_ans);
        }
    }
    
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    
    cout<<ans;
    return 0;
}
