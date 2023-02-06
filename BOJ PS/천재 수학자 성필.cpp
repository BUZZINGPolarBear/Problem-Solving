//
//  천재 수학자 성필.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/03.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;


void solve(){
    string inpt;
    stack<int> st;
    cin>>inpt;
    
    for(int i=0; i<inpt.size(); i++){
        if('0'<=inpt[i] && inpt[i]<='9') st.push(inpt[i] - '0');
        else{
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            
            switch(inpt[i]){
                case '+':
                    st.push(first + second);
                    break;
                case '-':
                    st.push(second - first);
                    break;
                case '*':
                    st.push(first * second);
                    break;
                case '/':
                    st.push(second / first);
                    break;
            }
        }
    }
    
    cout<<st.top();
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    
    return 0;
}
