//
//  UCPC는 무엇의 약자일까?.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/16.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string temp="", ans="";
    getline(cin, temp);
    stack<char> st;
    
    st.push('C');
    st.push('P');
    st.push('C');
    st.push('U');

    for(int i=0; i<temp.size(); i++){
        if(st.empty()){
            cout<<"I love UCPC";
            return 0;
        }
        
        if(temp[i] == st.top()) st.pop();
    }
    
    if(st.empty())cout<<"I love UCPC";
    else cout<<"I hate UCPC";
    
    return 0;
}
